#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(VECTOR, TestPlusVector)
{
    Custom_vector v1, v2;
    v1 = {1, 2, 3, 4};
    v2 = {1, 2, 3, 4};
    double result[] = {2, 4, 6, 8};

    Custom_vector res;
    res = v1 + v2;
    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 1);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1 = v1.transpouse();

    EXPECT_THROW({
        try
        {
            v1 + v2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vectors must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);

    v2 = v2.transpouse();
    res = v1 + v2;
    EXPECT_EQ(res.cnt_columns, 1);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1 = {1, 2};
    EXPECT_THROW({
        try
        {
            v1 + v2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vectors must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(VECTOR, TestPlusNumber)
{
    Custom_vector v1, v2;
    v1 = {1, 2, 3, 4};
    double result[] = {4, 5, 6, 7};
    Custom_vector res;
    res = v1 + 3;

    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 1);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1 = v1.transpouse();
    res = v1 + 3;
    EXPECT_EQ(res.cnt_columns, 1);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    res = 3 + v1;
    EXPECT_EQ(res.cnt_columns, 1);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }
}

TEST(VECTOR, TestPlusMatrix)
{
    Custom_vector v;
    v = {1, 2, 3, 4};

    Matrix m;
    m = {{1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}};

    double result[4][4] = {2, 4, 6, 8, 2, 4, 6, 8,
                           2, 4, 6, 8, 2, 4, 6, 8};

    Matrix res;
    res = v.add(m, "row");
    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j){
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
        }
    }

    res = m.add(v, "row");
    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j){
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
        }
    }

    res = v.add(m, "column");
    double result1[4][4] = {2, 3, 4, 5, 3, 4, 5, 6,
                           4, 5, 6, 7, 5, 6, 7, 8};

    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j){
            EXPECT_DOUBLE_EQ(result1[i][j], res(i, j));
        }
    }

    res = m.add(v, "column");
    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j){
            EXPECT_DOUBLE_EQ(result1[i][j], res(i, j));
        }
    }

    v = {1, 2};
    EXPECT_THROW({
        try
        {
            res = v.add(m, "row");
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vector and matrix must have same cnt_columns", e.what());
            throw;
        }
    },
                 invalid_argument); 
 
    EXPECT_THROW({
        try
        {
            res = v.add(m, "column");
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vector and matrix must have same cnt_rows", e.what());
            throw;
        }
    },
                 invalid_argument);    
}


TEST(MATRIX, TestPlusMatrix)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[2][3] = {2, 4, 6, 8, 10, 12};

    Matrix res;
    res = m1 + m1;
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    Matrix m2;
    m2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    EXPECT_THROW({
        try
        {
            m1 + m2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("matrix must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(MATRIX, TestPlusNumber)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[2][3] = {4, 5, 6, 7, 8, 9};

    Matrix res;
    res = m1 + 3;
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    res = 3 + m1;
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    int cnt = 3;
    res = cnt + m1;
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }
}