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
#include "chrono"
#include <es_odbc.h>
#include <string>
#include <vector>
#include <iostream>
// clang-format on
#define IT_SIZEOF(x) (NULL == (x) ? 0 : (sizeof((x)) / sizeof((x)[0])))
std::wstring dsn_name = L"DSN=test_dsn";
std::wstring user = L"admin";
std::wstring password = L"admin";
const wchar_t* const query =
    L"SELECT * FROM kibana_sample_data_flights limit 10000";
SQLHENV env = SQL_NULL_HENV;
SQLHDBC conn = SQL_NULL_HDBC;
SQLHSTMT hstmt = SQL_NULL_HSTMT;

int ConnectDataSource() {
    SQLTCHAR out_conn_string[1024];
    SQLSMALLINT out_conn_string_length;
    SQLRETURN ret;
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    std::cout << "SQLAllocHandle: " << ret << std::endl;
    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    std::cout << "SQLSetEnvAttr: " << ret << std::endl;
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &conn);
    std::cout << "SQLAllocHandle: " << ret << std::endl;
    ret = SQLDriverConnect(conn, NULL, (SQLTCHAR*)dsn_name.c_str(), SQL_NTS,
                            out_conn_string, IT_SIZEOF(out_conn_string),
                            &out_conn_string_length, SQL_DRIVER_COMPLETE);
    std::cout << "SQLDriverConnect: " << ret << std::endl;
    return ret;
}

void ExecuteQuery() {
    SQLExecDirect(hstmt, (SQLTCHAR*)query, SQL_NTS);
}

void main() {
    std::cout << "Connection:" << ConnectDataSource() << std::endl;
    SQLAllocHandle(SQL_HANDLE_STMT, conn, &hstmt);
    for (int i = 0; i < 10; i++) {
        auto start = std::chrono::steady_clock::now();
        ExecuteQuery();
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast< std::chrono::milliseconds >(
                         end - start)
                         .count()
                  << std::endl;
        SQLCloseCursor(hstmt);
    }
    SQLDisconnect(conn);
    SQLFreeHandle(SQL_HANDLE_ENV, env);
}
