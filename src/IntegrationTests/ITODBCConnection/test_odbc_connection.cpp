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

// clang-format off
#include "pch.h"
#include "unit_test_helper.h"
#include "it_odbc_helper.h"

#ifdef WIN32
#include <windows.h>
#endif
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <chrono>
// clang-format on

#define IT_SIZEOF(x) (NULL == (x) ? 0 : (sizeof((x)) / sizeof((x)[0])))

// SQLConnect constants
const SQLCHAR invalid_dsn_charwidth[]{"test_dsn"};
std::wstring wdsn_name = L"test_dsn";
std::wstring user = L"admin";
std::wstring pass = L"admin";

// SQLDriverConnect constants
std::wstring dsn_conn_string = L"DSN=test_dsn";

void AllocConnection(SQLHDBC* conn) {
    SQLHENV env = SQL_NULL_HENV;
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    ASSERT_TRUE(env != SQL_NULL_HENV) << "Environment handle not allocated";

    SQLRETURN set_env_attr_ret =
        SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    ASSERT_EQ(SQL_SUCCESS, set_env_attr_ret)
        << "Error while setting ODBC version on environment handle";

    SQLAllocHandle(SQL_HANDLE_DBC, env, conn);
    ASSERT_TRUE(conn != SQL_NULL_HDBC) << "Connection handle not allocated";
}

void ExecuteSqlConnect(SQLTCHAR* dsn_name, SQLRETURN* ret) {
    SQLHDBC conn = SQL_NULL_HDBC;
    ASSERT_NO_FATAL_FAILURE(AllocConnection(&conn));

    *ret = SQLConnect(
        conn, (SQLTCHAR*)dsn_name, SQL_NTS, (SQLTCHAR*)user.c_str(),
        static_cast< SQLSMALLINT >(user.length()), (SQLTCHAR*)pass.c_str(),
        static_cast< SQLSMALLINT >(pass.length()));

    LogAnyDiagnostics(SQL_HANDLE_DBC, conn, *ret);
}

void ExecuteSqlDriverConnect(SQLTCHAR* _conn_string,
                             SQLUSMALLINT completion_flag, SQLRETURN* ret) {
    SQLHDBC conn = SQL_NULL_HDBC;
    ASSERT_NO_FATAL_FAILURE(AllocConnection(&conn));

    SQLTCHAR out_conn_string[1024];
    SQLSMALLINT out_conn_string_length;
    *ret = SQLDriverConnect(conn, NULL, _conn_string, SQL_NTS, out_conn_string,
                            IT_SIZEOF(out_conn_string), &out_conn_string_length,
                            completion_flag);

    LogAnyDiagnostics(SQL_HANDLE_DBC, conn, *ret);
}

// Tests

// TODO: Investigate why this returns SQL_SUCCESS_WITH_INFO with empty diagrec.
// (AE-104).
TEST(TestSqlConnect, SqlSuccess) {
    SQLRETURN ret = SQL_ERROR;
    ASSERT_NO_FATAL_FAILURE(
        ExecuteSqlConnect((SQLTCHAR*)wdsn_name.c_str(), &ret));
    EXPECT_TRUE(SQL_SUCCEEDED(ret));
}

TEST(TestSqlConnect, SqlError) {
    SQLRETURN ret;
    ASSERT_NO_FATAL_FAILURE(
        ExecuteSqlConnect((SQLTCHAR*)invalid_dsn_charwidth, &ret));
    EXPECT_EQ(SQL_ERROR, ret);
}

// TODO: Investigate why this returns SQL_SUCCESS_WITH_INFO with empty diagrec.
// (AE-104)
TEST(TestSqlDriverConnect, DSNConnectionString) {
    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)dsn_conn_string.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    EXPECT_TRUE(SQL_SUCCEEDED(ret));
}

// TODO: Investigate why this returns SQL_SUCCESS_WITH_INFO with empty diagrec.
// (AE-104)
TEST(TestSqlDriverConnect, SqlDriverPrompt) {
    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)conn_string.c_str(), SQL_DRIVER_PROMPT,
                            &ret);
    EXPECT_TRUE(SQL_SUCCEEDED(ret));
}

// TODO: Investigate why this returns SQL_SUCCESS_WITH_INFO with empty diagrec.
// (AE-104)
TEST(TestSqlDriverConnect, SqlDriverComplete) {
    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)conn_string.c_str(), SQL_DRIVER_COMPLETE,
                            &ret);
    EXPECT_TRUE(SQL_SUCCEEDED(ret));
}

// TODO: Investigate why this returns SQL_SUCCESS_WITH_INFO with empty diagrec.
// (AE-104)
TEST(TestSqlDriverConnect, SqlDriverCompleteRequired) {
    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)conn_string.c_str(),
                            SQL_DRIVER_COMPLETE_REQUIRED, &ret);
    EXPECT_TRUE(SQL_SUCCEEDED(ret));
}

// TODO: Investigate why this returns SQL_SUCCESS_WITH_INFO with empty diagrec.
// (AE-104)
TEST(TestSqlDriverConnect, SqlDriverNoprompt) {
    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)conn_string.c_str(), SQL_DRIVER_NOPROMPT,
                            &ret);
    EXPECT_TRUE(SQL_SUCCEEDED(ret));
}

// TODO: Revisit when parser code is updated (AE-46)
// TEST(TestSqlDriverConnect, InvalidDriver) {
// 	std::wstring invalid_driver_conn_string =
// 		L"Driver=xxxx;DataBase=database_name;"
// 		L"Server=localhost;port=9200;"
// 		L"Uid=admin;Pwd=admin;";

// 	SQLRETURN ret;
// 	ExecuteSqlDriverConnect((SQLTCHAR*)invalid_driver_conn_string.c_str(),
//							SQL_DRIVER_COMPLETE, &ret);
// 	EXPECT_EQ(SQL_SUCCESS_WITH_INFO, ret);
// }

TEST(TestSqlDriverConnect, InvalidHost) {
    std::wstring invalid_host_conn_string =
        L"Driver={SQL Server};DataBase=database_name;"
        L"Host=8.8.8.8;Port=9200;"
        L"Username=admin;Password=admin;AuthenticationMode=BASIC";

    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)invalid_host_conn_string.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    EXPECT_EQ(SQL_ERROR, ret);
}

TEST(TestSqlDriverConnect, InvalidPort) {
    std::wstring invalid_port_conn_string =
        L"Driver={SQL Server};DataBase=database_name;"
        L"Host=localhost;Port=5432;"
        L"Username=admin;Password=admin;";

    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)invalid_port_conn_string.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    EXPECT_EQ(SQL_ERROR, ret);
}

// TODO: Revisit when parser code is updated (AE-46)
// This should return SQL_SUCCESS_WITH_INFO (SQLSTATE 01S00 - Invalid connection
// string attribute)
TEST(TestSqlDriverConnect, UnsupportedKeyword) {
    std::wstring unsupported_keyword_conn_string =
        L"Driver={SQL Server};DataBase=database_name;"
        L"Host=localhost;Port=5432;"
        L"Username=admin;Password=admin;extra=1;";

    SQLRETURN ret;
    ExecuteSqlDriverConnect((SQLTCHAR*)unsupported_keyword_conn_string.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    EXPECT_EQ(SQL_ERROR, ret);
}

TEST(TestSqlDriverConnect, Timeout1Second) {
    std::wstring one_second_timeout =
        L"Driver={SQL Server};DataBase=elasticsearch;"
        L"Host=8.8.8.8;Port=9200;"
        L"Username=admin;Password=admin;ResponseTimeout=1;";

    SQLRETURN ret;
    auto start = std::chrono::steady_clock::now();
    ExecuteSqlDriverConnect((SQLTCHAR*)one_second_timeout.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    auto end = std::chrono::steady_clock::now();
    auto time =
        std::chrono::duration_cast< std::chrono::milliseconds >(end - start)
            .count();
    std::cout << "TIME: " << time << std::endl;
    EXPECT_EQ(SQL_ERROR, ret);
#ifdef WIN32
    // Windows rounds up to nearest 4s with timeout, another user reported this
    // issue:
    // https://social.msdn.microsoft.com/Forums/vstudio/en-US/42ae1b2f-b120-4b46-9417-e594c3d02a5f/does-winhttpsettimeouts-support-small-timeouts?forum=vcgeneral
    EXPECT_GT(time, 3500);
    EXPECT_LT(time, 4500);
#else
    EXPECT_GT(time, 500);
    EXPECT_LT(time, 1500);
#endif
}

TEST(TestSqlDriverConnect, Timeout3Second) {
    std::wstring one_second_timeout =
        L"Driver={SQL Server};DataBase=elasticsearch;"
        L"Host=8.8.8.8;Port=9200;"
        L"Username=admin;Password=admin;ResponseTimeout=3;";

    SQLRETURN ret;
    auto start = std::chrono::steady_clock::now();
    ExecuteSqlDriverConnect((SQLTCHAR*)one_second_timeout.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    auto end = std::chrono::steady_clock::now();
    auto time =
        std::chrono::duration_cast< std::chrono::milliseconds >(end - start)
            .count();
    std::cout << "TIME: " << time << std::endl;
    EXPECT_EQ(SQL_ERROR, ret);
#ifdef WIN32
    // Windows rounds up to nearest 4s with timeout, another user reported this
    // issue:
    // https://social.msdn.microsoft.com/Forums/vstudio/en-US/42ae1b2f-b120-4b46-9417-e594c3d02a5f/does-winhttpsettimeouts-support-small-timeouts?forum=vcgeneral
    EXPECT_GT(time, 3500);
    EXPECT_LT(time, 4500);
#else
    EXPECT_GT(time, 2500);
    EXPECT_LT(time, 3500);
#endif
}

TEST(TestSqlDriverConnect, Timeout7Second) {
    std::wstring seven_second_timeout =
        L"Driver={SQL Server};DataBase=elasticsearch;"
        L"Host=8.8.8.8;Port=9200;"
        L"Username=admin;Password=admin;ResponseTimeout=7;";

    SQLRETURN ret;
    auto start = std::chrono::steady_clock::now();
    ExecuteSqlDriverConnect((SQLTCHAR*)seven_second_timeout.c_str(),
                            SQL_DRIVER_COMPLETE, &ret);
    auto end = std::chrono::steady_clock::now();
    auto time =
        std::chrono::duration_cast< std::chrono::milliseconds >(end - start)
            .count();
    std::cout << "TIME: " << time << std::endl;
    EXPECT_EQ(SQL_ERROR, ret);
#ifdef WIN32
    // Windows rounds up to nearest 4s with timeout, another user reported this
    // issue:
    // https://social.msdn.microsoft.com/Forums/vstudio/en-US/42ae1b2f-b120-4b46-9417-e594c3d02a5f/does-winhttpsettimeouts-support-small-timeouts?forum=vcgeneral
    EXPECT_GT(time, 7500);
    EXPECT_LT(time, 8500);
#else
    EXPECT_GT(time, 6500);
    EXPECT_LT(time, 7500);
#endif
}

class TestSQLDisconnect : public testing::Test {
   public:
    TestSQLDisconnect() {
    }

    void SetUp() {
    }

    void TearDown() {
    }

    ~TestSQLDisconnect() {
        // cleanup any pending stuff, but no exceptions allowed
    }

    SQLHDBC m_conn = SQL_NULL_HDBC;
};

TEST_F(TestSQLDisconnect, TestSuccess) {
    ASSERT_NO_THROW(
        AllocConnection((SQLTCHAR*)conn_string.c_str(), &m_conn, true, true));
    EXPECT_EQ(SQL_SUCCESS, SQLDisconnect(m_conn));
}

TEST_F(TestSQLDisconnect, TestReconnectOnce) {
    for (int i = 0; i <= 1; i++) {
        ASSERT_NO_THROW((AllocConnection((SQLTCHAR*)conn_string.c_str(),
                                         &m_conn, true, true)));
        EXPECT_EQ(SQL_SUCCESS, SQLDisconnect(m_conn));
    }
}

TEST_F(TestSQLDisconnect, TestReconnectMultipleTimes) {
    for (int i = 0; i <= 10; i++) {
        ASSERT_NO_THROW((AllocConnection((SQLTCHAR*)conn_string.c_str(),
                                         &m_conn, true, true)));
        EXPECT_EQ(SQL_SUCCESS, SQLDisconnect(m_conn));
    }
}

TEST_F(TestSQLDisconnect, TestDisconnectWithoutConnect) {
    SQLHENV env = NULL;
    ASSERT_NO_THROW(SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env));
    ASSERT_NO_THROW(SQLAllocHandle(SQL_HANDLE_DBC, env, &m_conn));
    EXPECT_EQ(SQL_ERROR, SQLDisconnect(m_conn));
}

int main(int argc, char** argv) {
    testing::internal::CaptureStdout();
    ::testing::InitGoogleTest(&argc, argv);

    int failures = RUN_ALL_TESTS();

    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output << std::endl;
    std::cout << (failures ? "Not all tests passed." : "All tests passed")
              << std::endl;
    WriteFileIfSpecified(argv, argv + argc, "-fout", output);

    return failures;
}
