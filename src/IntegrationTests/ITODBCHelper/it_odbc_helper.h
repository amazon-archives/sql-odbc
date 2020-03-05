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

#ifndef IT_ODBC_HELPER_H
#define IT_ODBC_HELPER_H

#ifdef WIN32
#include <windows.h>
#endif
#include <sql.h>
#include <sqlext.h>

#include <iostream>

#include "unit_test_helper.h"

// SQLSTATEs
#define SQLSTATE_STRING_DATA_RIGHT_TRUNCATED (SQLWCHAR*)L"01004"
#define SQLSTATE_INVALID_DESCRIPTOR_INDEX (SQLWCHAR*)L"07009"
#define SQLSTATE_GENERAL_ERROR (SQLWCHAR*)L"HY000"
#define SQLSTATE_INVALID_DESCRIPTOR_FIELD_IDENTIFIER (SQLWCHAR*)L"HY091"

#define IT_SIZEOF(x) (NULL == (x) ? 0 : (sizeof((x)) / sizeof((x)[0])))

std::wstring conn_string =
    use_ssl ? L"Driver={Elasticsearch ODBC};"
              L"host=https://localhost;port=9200;"
              L"user=admin;password=admin;auth=BASIC;useSSL="
              L"1;hostnameVerification=0;logLevel=0;logOutput=C:\\;"
              L"responseTimeout=1;"
            : L"Driver={Elasticsearch ODBC};"
              L"host=localhost;port=9200;"
              L"user=admin;password=admin;auth=BASIC;useSSL="
              L"0;hostnameVerification=0;logLevel=0;logOutput=C:\\;"
              L"responseTimeout=1;";

void AllocConnection(SQLTCHAR* connection_string, SQLHDBC* db_connection,
                     bool throw_on_error, bool log_diag);
void AllocStatement(SQLTCHAR* connection_string, SQLHDBC* db_connection,
                    SQLHSTMT* h_statement, bool throw_on_error, bool log_diag);
void LogAnyDiagnostics(SQLSMALLINT handle_type, SQLHANDLE handle, SQLRETURN ret,
                       SQLTCHAR* msg_return = NULL, const SQLSMALLINT sz = 0);
bool CheckSQLSTATE(SQLSMALLINT handle_type, SQLHANDLE handle,
                   SQLWCHAR* expected_sqlstate, bool log_message);
bool CheckSQLSTATE(SQLSMALLINT handle_type, SQLHANDLE handle,
                   SQLWCHAR* expected_sqlstate);
std::wstring QueryBuilder(const std::wstring& column,
                          const std::wstring& dataset,
                          const std::wstring& count);
std::wstring QueryBuilder(const std::wstring& column,
                          const std::wstring& dataset);
void CloseCursor(SQLHSTMT* h_statement, bool throw_on_error, bool log_diag);
std::string u16string_to_string(const std::u16string& src);
std::u16string string_to_u16string(const std::string& src);

#endif
