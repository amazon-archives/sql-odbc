/*
 * Copyright <2019> Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 *
 */

#include "es_communication.h"

// elasticodbc needs to be included before mylog, otherwise mylog will generate
// compiler warnings
// clang-format off
#include "es_odbc.h"
#include "mylog.h"
#include <aws/core/utils/StringUtils.h>
#include <aws/core/client/RetryStrategy.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/auth/AWSCredentialsProvider.h>
#include <aws/core/http/HttpClient.h>
// clang-format on

static const std::string ctype = "application/json";
static const std::string SQL_ENDPOINT_FORMAT_JDBC =
    "/_opendistro/_sql?format=jdbc";
static const std::string PLUGIN_ENDPOINT_FORMAT_JSON =
    "/_cat/plugins?format=json";
static const std::string OPENDISTRO_SQL_PLUGIN_NAME = "opendistro_sql";
static const int HTTP_SUCCESS_OK = 200;
static const std::string ALLOCATION_TAG = "AWS_SIGV4_AUTH";
static const std::string SERVICE_NAME = "es";

ESCommunication::ESCommunication()
#ifdef __APPLE__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreorder"
#endif  // __APPLE__
    : m_status(ConnStatusType::CONNECTION_BAD),
      m_valid_connection_options(false),
      m_error_message(""),
      m_client_encoding(m_supported_client_encodings[0])
#ifdef __APPLE__
#pragma clang diagnostic pop
#endif  // __APPLE__
{
    Aws::InitAPI(m_options);
}

ESCommunication::~ESCommunication() {
    Aws::ShutdownAPI(m_options);
}

std::string ESCommunication::GetErrorMessage() {
    return m_error_message;
}

bool ESCommunication::ConnectionOptions(runtime_options& rt_opts,
                                        bool use_defaults, int expand_dbname,
                                        unsigned int option_count) {
    (void)(expand_dbname);
    (void)(option_count);
    (void)(use_defaults);
    m_rt_opts = rt_opts;
    return CheckConnectionOptions();
}

bool ESCommunication::ConnectionOptions2() {
    return true;
}

bool ESCommunication::ConnectDBStart() {
    LogMsg("Starting DB connection.");
    m_status = ConnStatusType::CONNECTION_BAD;
    if (!m_valid_connection_options) {
        m_error_message =
            "Invalid connection options, unable to connect to DB.";
        LogMsg(m_error_message.c_str());
        DropDBConnection();
        return false;
    }

    m_status = ConnStatusType::CONNECTION_NEEDED;
    if (!EstablishConnection()) {
        if (m_error_message.empty())
            m_error_message = "Failed to establish connection to DB.";
        LogMsg(m_error_message.c_str());
        DropDBConnection();
        return false;
    }

    LogMsg("Connection established.");
    m_status = ConnStatusType::CONNECTION_OK;
    return true;
}

ConnStatusType ESCommunication::GetConnectionStatus() {
    return m_status;
}

void ESCommunication::DropDBConnection() {
    LogMsg("Dropping DB connection.");
    if (m_http_client) {
        m_http_client.reset();
    }
    m_status = ConnStatusType::CONNECTION_BAD;
    if (!m_result_queue.empty()) {
        m_result_queue = std::queue< std::unique_ptr< ESResult > >();
    }
}

bool ESCommunication::CheckConnectionOptions() {
    LogMsg("Verifying connection options.");
    m_error_message = "";
    if (m_rt_opts.auth.auth_type != AUTHTYPE_NONE
        && m_rt_opts.auth.auth_type != AUTHTYPE_IAM) {
        if (m_rt_opts.auth.auth_type == AUTHTYPE_BASIC) {
            if (m_rt_opts.auth.username.empty()
                || m_rt_opts.auth.password.empty()) {
                m_error_message = AUTHTYPE_BASIC
                    " authentication requires a username and password.";
            }
        } else {
            m_error_message = "Unknown authentication type: '"
                              + m_rt_opts.auth.auth_type + "'";
        }
    } else if (m_rt_opts.conn.server == "") {
        m_error_message = "Host connection option was not specified.";
    }

    if (m_error_message != "") {
        LogMsg(m_error_message.c_str());
        m_valid_connection_options = false;
        return false;
    } else {
        LogMsg("Required connection option are valid.");
        m_valid_connection_options = true;
    }
    return m_valid_connection_options;
}

void ESCommunication::InitializeConnection() {
    Aws::Client::ClientConfiguration config;
    config.scheme = (m_rt_opts.crypt.use_ssl ? Aws::Http::Scheme::HTTPS
                                             : Aws::Http::Scheme::HTTP);
    config.verifySSL = m_rt_opts.crypt.verify_server;
    long response_timeout =
        static_cast< long >(DEFAULT_RESPONSE_TIMEOUT) * 1000L;
    try {
        response_timeout =
            std::stol(m_rt_opts.conn.timeout, nullptr, 10) * 1000L;
    } catch (...) {
    }
    config.connectTimeoutMs = response_timeout;
    config.httpRequestTimeoutMs = response_timeout;
    config.requestTimeoutMs = response_timeout;
    m_http_client = Aws::Http::CreateHttpClient(config);
}

void ESCommunication::IssueRequest(
    const std::string& endpoint, const Aws::Http::HttpMethod request_type,
    const std::string& content_type, const std::string& query,
    std::shared_ptr< Aws::Http::HttpResponse >& response) {
    // Generate http request
    std::shared_ptr< Aws::Http::HttpRequest > request =
        Aws::Http::CreateHttpRequest(
            Aws::String(
                m_rt_opts.conn.server
                + (m_rt_opts.conn.port.empty() ? "" : ":" + m_rt_opts.conn.port)
                + endpoint),
            request_type,
            Aws::Utils::Stream::DefaultResponseStreamFactoryMethod);

    // Handle authentication
    if (m_rt_opts.auth.auth_type == AUTHTYPE_BASIC) {
        std::string userpw_str =
            m_rt_opts.auth.username + ":" + m_rt_opts.auth.password;
        Aws::Utils::Array< unsigned char > userpw_arr(
            reinterpret_cast< const unsigned char* >(userpw_str.c_str()),
            userpw_str.length());
        std::string hashed_userpw =
            Aws::Utils::HashingUtils::Base64Encode(userpw_arr);
        request->SetAuthorization("Basic " + hashed_userpw);
    } else if (m_rt_opts.auth.auth_type == AUTHTYPE_IAM) {
        std::shared_ptr< Aws::Auth::EnvironmentAWSCredentialsProvider >
            credential_provider =
                Aws::MakeShared< Aws::Auth::EnvironmentAWSCredentialsProvider >(
                    ALLOCATION_TAG.c_str());
        Aws::Client::AWSAuthV4Signer signer(credential_provider,
                                            SERVICE_NAME.c_str(),
                                            m_rt_opts.auth.region.c_str());
        signer.SignRequest(*request);
    }

    // Set header type
    if (!content_type.empty())
        request->SetHeaderValue(Aws::Http::CONTENT_TYPE_HEADER, ctype);

    // Set body
    if (!query.empty()) {
        rabbit::object body;
        body["query"] = query;
        std::shared_ptr< Aws::StringStream > aws_ss =
            Aws::MakeShared< Aws::StringStream >("RabbitStream");
        *aws_ss << std::string(body.str());
        request->AddContentBody(aws_ss);
        request->SetContentLength(std::to_string(body.str().size()));
    }

    // Issue request
    response = m_http_client->MakeRequest(request);
}

bool ESCommunication::IsSQLPluginInstalled(const std::string& plugin_response) {
    try {
        rabbit::document doc;
        doc.parse(plugin_response);

        rabbit::array plugin_array = doc;
        for (auto it : plugin_array) {
            if (it.has("component") && it.has("version")) {
                std::string plugin_name = it.at("component").as_string();
                if (!plugin_name.compare(OPENDISTRO_SQL_PLUGIN_NAME)) {
                    std::string sql_plugin_version =
                        it.at("version").as_string();
                    LogMsg(std::string("Found SQL plugin version '"
                                       + sql_plugin_version + "'.")
                               .c_str());
                    return true;
                }
            } else {
                m_error_message =
                    "Could not find all necessary fields in the plugin "
                    "response object. "
                    "(\"component\", \"version\")";
                throw std::runtime_error(m_error_message.c_str());
            }
        }
    } catch (const rabbit::type_mismatch& e) {
        m_error_message =
            "Error parsing endpoint response: " + std::string(e.what());
    } catch (const rabbit::parse_error& e) {
        m_error_message =
            "Error parsing endpoint response: " + std::string(e.what());
    } catch (const std::exception& e) {
        m_error_message =
            "Error parsing endpoint response: " + std::string(e.what());
    } catch (...) {
        m_error_message =
            "Unknown exception thrown when parsing plugin endpoint response.";
    }

    LogMsg(m_error_message.c_str());
    return false;
}

bool ESCommunication::EstablishConnection() {
    // Generate HttpClient Connection class if it does not exist
    LogMsg("Attempting to establish DB connection.");
    if (!m_http_client) {
        InitializeConnection();
    }

    // Check whether SQL plugin has been installed on the Elasticsearch server.
    // This is required for executing driver queries with the server.
    LogMsg("Checking for SQL plugin");
    std::shared_ptr< Aws::Http::HttpResponse > response = nullptr;
    IssueRequest(PLUGIN_ENDPOINT_FORMAT_JSON, Aws::Http::HttpMethod::HTTP_GET,
                 "", "", response);
    if (response == nullptr) {
        m_error_message =
            "The SQL plugin must be installed in order to use this driver. "
            "Received NULL response.";
    } else {
        std::stringstream ss;
        ss << response->GetResponseBody().rdbuf();
        if (response->GetResponseCode() != Aws::Http::HttpResponseCode::OK) {
            m_error_message =
                "The SQL plugin must be installed in order to use this driver.";
            if (response->HasClientError())
                m_error_message += " Client error: '"
                                   + response->GetClientErrorMessage() + "'.";
            if (!ss.str().empty())
                m_error_message += " Response error: '" + ss.str() + "'.";
        } else {
            if (IsSQLPluginInstalled(ss.str())) {
                return true;
            } else {
                if (m_error_message.empty())
                    m_error_message =
                        "The SQL plugin must be installed in order to use this "
                        "driver. Response body: '"
                        + ss.str() + "'";
            }
        }
    }
    LogMsg(m_error_message.c_str());
    return false;
}

int ESCommunication::ExecDirect(const char* query) {
    if (!query) {
        m_error_message = "Query is NULL";
        LogMsg(m_error_message.c_str());
        return -1;
    } else if (!m_http_client) {
        m_error_message = "Unable to connect. Please try connecting again.";
        LogMsg(m_error_message.c_str());
        return -1;
    }

    // Prepare statement
    std::string statement(query);
    std::string msg = "Attempting to execute a query \"" + statement + "\"";
    LogMsg(msg.c_str());

    // Issue request
    std::shared_ptr< Aws::Http::HttpResponse > response = nullptr;
    IssueRequest(SQL_ENDPOINT_FORMAT_JDBC, Aws::Http::HttpMethod::HTTP_POST,
                 ctype, statement, response);

    // Validate response
    if (response == nullptr) {
        m_error_message =
            "Failed to receive response from query. "
            "Received NULL response.";
        LogMsg(m_error_message.c_str());
        return -1;
    }

    // Convert body from Aws IOStream to string
    std::stringstream ss;
    ss << response->GetResponseBody().rdbuf();
    std::string body(ss.str());

    // If response was not valid, set error
    if (response->GetResponseCode() != Aws::Http::HttpResponseCode::OK) {
        m_error_message =
            "Http response code was not OK. Code received: "
            + std::to_string(static_cast< long >(response->GetResponseCode()))
            + ".";
        if (response->HasClientError())
            m_error_message +=
                " Client error: '" + response->GetClientErrorMessage() + "'.";
        if (!body.empty()) {
            m_error_message += " Response error: '" + body + "'.";
        }
        LogMsg(m_error_message.c_str());
        return -1;
    }

    // Add to result queue and return
    ESResult* result = new ESResult;
    ConstructESResult(body, *result);
    m_result_queue.push(std::unique_ptr< ESResult >(result));
    return 0;
}

void ESCommunication::ConstructESResult(std::string& query_result_json,
                                        ESResult& result) {
    rabbit::document doc;
    doc.parse(query_result_json);

    rabbit::array schema_array = doc["schema"];
    for (rabbit::array::iterator it = schema_array.begin();
         it != schema_array.end(); ++it) {
        std::string column_name = it->at("name").as_string();

        ColumnInfo col_info;
        col_info.field_name = column_name;
        col_info.type_oid = KEYWORD_TYPE_OID;
        col_info.type_size = KEYWORD_TYPE_SIZE;
        col_info.display_size = KEYWORD_DISPLAY_SIZE;
        col_info.length_of_str = KEYWORD_TYPE_SIZE;
        col_info.relation_id = 0;
        col_info.attribute_number = 0;

        result.column_info.push_back(col_info);
    }

    result.command_type = "SELECT";
    result.num_fields = (uint16_t)schema_array.size();
    result.result_json = query_result_json;
}

inline void ESCommunication::LogMsg(const char* msg) {
#if WIN32
#pragma warning(push)
#pragma warning(disable : 4551)
#endif  // WIN32
    // cppcheck outputs an erroneous missing argument error which breaks build.
    // Disable for this function call
    MYLOG(0, "%s\n", msg);
#if WIN32
#pragma warning(pop)
#endif  // WIN32
}

ESResult* ESCommunication::PopResult() {
    if (m_result_queue.empty()) {
        LogMsg("Result queue is empty; returning null result.");
        return NULL;
    }
    ESResult* result = m_result_queue.front().release();
    m_result_queue.pop();
    return result;
}

// TODO: Send query to database to get encoding
std::string ESCommunication::GetClientEncoding() {
    return m_client_encoding;
}

// TODO: Send query to database to set encoding
bool ESCommunication::SetClientEncoding(std::string& encoding) {
    if (std::find(m_supported_client_encodings.begin(),
                  m_supported_client_encodings.end(), encoding)
        != m_supported_client_encodings.end()) {
        m_client_encoding = encoding;
        return true;
    }
    LogMsg(std::string("Failed to find encoding " + encoding).c_str());
    return false;
}

std::string ESCommunication::GetServerVersion() {
    if (!m_http_client) {
        InitializeConnection();
    }

    // Issue request
    std::shared_ptr< Aws::Http::HttpResponse > response = nullptr;
    IssueRequest("", Aws::Http::HttpMethod::HTTP_GET, "", "", response);
    if (response == nullptr) {
        m_error_message =
            "Failed to receive response from query. "
            "Received NULL response.";
        LogMsg(m_error_message.c_str());
        return "";
    }

    // Parse server version
    if (response->GetResponseCode() == Aws::Http::HttpResponseCode::OK) {
        try {
            std::stringstream ss;
            ss << response->GetResponseBody().rdbuf();
            rabbit::document doc;
            doc.parse(ss.str());
            if (doc.has("version") && doc["version"].has("number")) {
                return doc["version"]["number"].as_string();
            }

        } catch (const rabbit::type_mismatch& e) {
            m_error_message = "Error parsing main endpoint response: "
                              + std::string(e.what());
            LogMsg(m_error_message.c_str());
        } catch (const rabbit::parse_error& e) {
            m_error_message = "Error parsing main endpoint response: "
                              + std::string(e.what());
            LogMsg(m_error_message.c_str());
        } catch (const std::exception& e) {
            m_error_message = "Error parsing main endpoint response: "
                              + std::string(e.what());
            LogMsg(m_error_message.c_str());
        } catch (...) {
            LogMsg(
                "Unknown exception thrown when parsing main endpoint "
                "response.");
        }
    }
    LogMsg(m_error_message.c_str());
    return "";
}
