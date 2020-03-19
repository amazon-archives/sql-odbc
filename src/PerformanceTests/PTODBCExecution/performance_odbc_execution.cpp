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
const wchar_t* const query =
    L"SELECT * FROM kibana_sample_data_flights limit 10000";

bool SQLSUCCEEDED(int ret) {
    return (ret == 0 || ret == 1)? true : false;
}

int main() {
    SQLTCHAR out_conn_string[1024];
    SQLSMALLINT out_conn_string_length;
    SQLHENV env = SQL_NULL_HENV;
    SQLHDBC conn = SQL_NULL_HDBC;
    SQLHSTMT hstmt = SQL_NULL_HSTMT;
    SQLRETURN ret = -1;
    try {
        if (SQLSUCCEEDED(SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env))
            && SQLSUCCEEDED(SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION,
                                          (void*)SQL_OV_ODBC3, 0))
            && SQLSUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC, env, &conn))
            && SQLSUCCEEDED(SQLDriverConnect(
                conn, NULL, (SQLTCHAR*)dsn_name.c_str(), SQL_NTS,
                out_conn_string, IT_SIZEOF(out_conn_string),
                &out_conn_string_length, SQL_DRIVER_COMPLETE))
            && SQLSUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, conn, &hstmt))) {
            std::cout << "Time(ms) for query execution:" << std::endl;
            for (int i = 0; i < 12; i++) {
                //Calculate time(ms) for query execution
                auto start = std::chrono::steady_clock::now();
                ret = SQLExecDirect(hstmt, (SQLTCHAR*)query, SQL_NTS);
                auto end = std::chrono::steady_clock::now();
                std::cout<< std::chrono::duration_cast< std::chrono::milliseconds >(
                           end - start).count()<< std::endl;
                SQLCloseCursor(hstmt);
            }
            SQLDisconnect(conn);
            SQLFreeHandle(SQL_HANDLE_ENV, env);
        }
    } catch (...) {
        std::cout << "Exception occurred"<<std::endl;
    }
    return ret;
}