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
#include "chrono"
// clang-format on

#define BIND_SIZE 255
#define ROWSET_SIZE_5 5
#define ROWSET_SIZE_50 50
#define SINGLE_ROW 1
#define ITERATION_COUNT 10

#ifndef WIN32
typedef SQLULEN SQLROWCOUNT;
typedef SQLULEN SQLROWSETSIZE;
typedef SQLULEN SQLTRANSID;
typedef SQLLEN SQLROWOFFSET;
#endif

const char16_t* const m_query =
    u"SELECT * FROM kibana_sample_data_flights limit 10000";

typedef struct Col {
    SQLLEN data_len;
    SQLCHAR data_dat[BIND_SIZE];
} Col;

class TestPerformance : public testing::Test {
   public:
    TestPerformance() {
    }
    void SetUp() {
        AllocStatement((SQLTCHAR*)conn_string.c_str(), &m_conn, &m_hstmt, true,
                       true);
    }
    void TearDown() {
        SQLDisconnect(m_conn);
    }

   protected:
    SQLHDBC m_conn = SQL_NULL_HDBC;
    SQLHSTMT m_hstmt = SQL_NULL_HSTMT;
};

TEST_F(TestPerformance, Time_Execute) {
    auto start = std::chrono::steady_clock::now();
    SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
    auto end = std::chrono::steady_clock::now();

    ASSERT_TRUE(SQL_SUCCEEDED(ret));
    std::cout << "Time required for execution: "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_BindColumn_FetchSingleRow) {
    SQLSMALLINT total_columns = 0;
    int row_count = 0;

    SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
    ASSERT_TRUE(SQL_SUCCEEDED(ret));

    SQLNumResultCols(m_hstmt, &total_columns);

    std::vector< std::vector< Col > > cols(total_columns);
    for (size_t i = 0; i < cols.size(); i++)
        cols[i].resize(SINGLE_ROW);

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < cols.size(); i++)
        ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                         (SQLPOINTER)&cols[i][0].data_dat[i], 255,
                         &cols[i][0].data_len);

    while (SQLFetch(m_hstmt) == SQL_SUCCESS)
        row_count++;

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time required for bind and fetch: "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_BindColumn_Fetch5Rows) {
    SQLROWSETSIZE row_count = 0;
    SQLSMALLINT total_columns = 0;
    SQLROWSETSIZE rows_fetched = 0;
    SQLUSMALLINT row_status[ROWSET_SIZE_5];
    SQLSetStmtAttr(m_hstmt, SQL_ROWSET_SIZE, (void*)ROWSET_SIZE_5, 0);

    SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
    ASSERT_TRUE(SQL_SUCCEEDED(ret));

    SQLNumResultCols(m_hstmt, &total_columns);

    std::vector< std::vector< Col > > cols(total_columns);
    for (size_t i = 0; i < cols.size(); i++)
        cols[i].resize(ROWSET_SIZE_5);

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < cols.size(); i++)
        ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                         (SQLPOINTER)&cols[i][0].data_dat[i], BIND_SIZE,
                         &cols[i][0].data_len);

    while (
        SQLExtendedFetch(m_hstmt, SQL_FETCH_NEXT, 0, &rows_fetched, row_status)
        == SQL_SUCCESS) {
        row_count += rows_fetched;
        if (rows_fetched < ROWSET_SIZE_5)
            break;
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time required for bind and fetch multiple rows at a time: "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_BindColumn_Fetch50Rows) {
    SQLROWSETSIZE row_count = 0;
    SQLSMALLINT total_columns = 0;
    SQLROWSETSIZE rows_fetched = 0;
    SQLUSMALLINT row_status[ROWSET_SIZE_50];
    SQLSetStmtAttr(m_hstmt, SQL_ROWSET_SIZE, (void*)ROWSET_SIZE_50, 0);

    SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
    ASSERT_TRUE(SQL_SUCCEEDED(ret));

    SQLNumResultCols(m_hstmt, &total_columns);

    std::vector< std::vector< Col > > cols(total_columns);
    for (size_t i = 0; i < cols.size(); i++)
        cols[i].resize(ROWSET_SIZE_50);

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < cols.size(); i++)
        ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                         (SQLPOINTER)&cols[i][0].data_dat[i], BIND_SIZE,
                         &cols[i][0].data_len);

    while (
        SQLExtendedFetch(m_hstmt, SQL_FETCH_NEXT, 0, &rows_fetched, row_status)
        == SQL_SUCCESS) {
        row_count += rows_fetched;
        if (rows_fetched < ROWSET_SIZE_50)
            break;
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time required for bind and fetch multiple rows at a time: "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_Execute_FetchSingleRow) {
    SQLSMALLINT total_columns = 0;
    int row_count = 0;

    auto start = std::chrono::steady_clock::now();

    SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
    ASSERT_TRUE(SQL_SUCCEEDED(ret));

    SQLNumResultCols(m_hstmt, &total_columns);

    std::vector< std::vector< Col > > cols(total_columns);
    for (size_t i = 0; i < cols.size(); i++)
        cols[i].resize(SINGLE_ROW);

    for (size_t i = 0; i < cols.size(); i++)
        ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                         (SQLPOINTER)&cols[i][0].data_dat[i], BIND_SIZE,
                         &cols[i][0].data_len);

    while (SQLFetch(m_hstmt) == SQL_SUCCESS)
        row_count++;

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time required to excute a query and retrieve results: "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_Execute_FetchSingleRow_10Times) {
    int row_count = 0;
    SQLSMALLINT total_columns = 0;

    auto start = std::chrono::steady_clock::now();

    for (int repeat = 0; repeat < 10; repeat++) {
        SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
        ASSERT_TRUE(SQL_SUCCEEDED(ret));

        SQLNumResultCols(m_hstmt, &total_columns);

        std::vector< std::vector< Col > > cols(total_columns);
        for (size_t i = 0; i < cols.size(); i++)
            cols[i].resize(SINGLE_ROW);

        for (size_t i = 0; i < cols.size(); i++)
            ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                             (SQLPOINTER)&cols[i][0].data_dat[i], BIND_SIZE,
                             &cols[i][0].data_len);

        while (SQLFetch(m_hstmt) == SQL_SUCCESS)
            row_count++;

        SQLCloseCursor(m_hstmt);
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time required to excute a query and retrieve results: "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_Execute_Fetch5Rows_10Times) {
    SQLROWSETSIZE row_count = 0;
    SQLSMALLINT total_columns = 0;
    SQLROWSETSIZE rows_fetched = 0;
    SQLUSMALLINT row_status[ROWSET_SIZE_5];

    SQLSetStmtAttr(m_hstmt, SQL_ROWSET_SIZE, (void*)ROWSET_SIZE_5, 0);

    auto start = std::chrono::steady_clock::now();

    for (int repeat = 0; repeat < 10; repeat++) {
        SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
        ASSERT_TRUE(SQL_SUCCEEDED(ret));

        SQLNumResultCols(m_hstmt, &total_columns);

        std::vector< std::vector< Col > > cols(total_columns);
        for (size_t i = 0; i < cols.size(); i++)
            cols[i].resize(ROWSET_SIZE_5);

        for (size_t i = 0; i < cols.size(); i++)
            ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                             (SQLPOINTER)&cols[i][0].data_dat[i], BIND_SIZE,
                             &cols[i][0].data_len);

        while (SQLExtendedFetch(m_hstmt, SQL_FETCH_NEXT, 0, &rows_fetched,
                                row_status)
               == SQL_SUCCESS) {
            row_count += rows_fetched;
            if (rows_fetched < ROWSET_SIZE_5)
                break;
        }

        SQLCloseCursor(m_hstmt);
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time required for excute a query and retrieve results : "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

TEST_F(TestPerformance, Time_Execute_Fetch50Rows_10Times) {
    SQLROWSETSIZE row_count = 0;
    SQLSMALLINT total_columns = 0;
    SQLROWSETSIZE rows_fetched = 0;
    SQLUSMALLINT row_status[ROWSET_SIZE_50];

    SQLSetStmtAttr(m_hstmt, SQL_ROWSET_SIZE, (void*)ROWSET_SIZE_50, 0);

    auto start = std::chrono::steady_clock::now();
    for (int repeat = 0; repeat < 10; repeat++) {
        SQLRETURN ret = SQLExecDirect(m_hstmt, (SQLTCHAR*)m_query, SQL_NTS);
        ASSERT_TRUE(SQL_SUCCEEDED(ret));

        SQLNumResultCols(m_hstmt, &total_columns);

        std::vector< std::vector< Col > > cols(total_columns);
        for (size_t i = 0; i < cols.size(); i++)
            cols[i].resize(ROWSET_SIZE_50);

        for (size_t i = 0; i < cols.size(); i++)
            ret = SQLBindCol(m_hstmt, (SQLUSMALLINT)i + 1, SQL_C_CHAR,
                             (SQLPOINTER)&cols[i][0].data_dat[i], BIND_SIZE,
                             &cols[i][0].data_len);

        while (SQLExtendedFetch(m_hstmt, SQL_FETCH_NEXT, 0, &rows_fetched,
                                row_status)
               == SQL_SUCCESS) {
            row_count += rows_fetched;
            if (rows_fetched < ROWSET_SIZE_50)
                break;
        }

        SQLCloseCursor(m_hstmt);
    }
    auto end = std::chrono::steady_clock::now();

    std::cout << "Time required for excute a query and retrieve results : "
              << std::chrono::duration_cast< std::chrono::milliseconds >(
                     end - start)
                     .count()
              << " ms" << std::endl
              << "Number of rows retrieved : " << row_count << std::endl
              << "Number of columns retrieved: " << total_columns << std::endl
              << "_____________________________________________________________"
                 "________________"
              << std::endl;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int failures = 0;
    for (size_t iteration = 0; iteration < ITERATION_COUNT; iteration++)
        failures += RUN_ALL_TESTS();
    std::cout << (failures ? "Not all tests passed." : "All tests passed")
              << std::endl;
}
