#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(VECTOR, TestMinusVector)
{
    Custom_vector v1, v2;
    v1 = {1, 2, 3, 4};
    v2 = {1, 2, 3, 4};
    double result[] = {0, 0, 0, 0};

    Custom_vector res;
    res = v1 - v2;
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1 = v1.transpouse();

    EXPECT_THROW({
        try
        {
            v1 - v2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vectors must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);

    v2 = v2.transpouse();
    res = v1 - v2;
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1 = {1, 2};
    EXPECT_THROW({
        try
        {
            v1 - v2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vectors must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(VECTOR, TestMinusNumber)
{
    Custom_vector v1, v2;
    v1 = {1, 2, 3, 4};
    double result[] = {0, 1, 2, 3};
    Custom_vector res;
    res = v1 - 1;

    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 1);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1 = v1.transpouse();
    res = v1 - 1;
    EXPECT_EQ(res.cnt_columns, 1);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    double result1[] = {3, 2, 1, 0};
    res = 4 - v1;
    EXPECT_EQ(res.cnt_columns, 1);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result1[i], res(i));
    }
}

TEST(MATRIX, TestMinus)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[2][3] = {0, 0, 0, 0, 0, 0};

    Matrix res;
    res = m1 - m1;
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
            m1 - m2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("matrix must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(MATRIX, TestMinusNumber)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[2][3] = {0, 1, 2, 3, 4, 5};

    Matrix res;
    res = m1 - 1;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    res = 6 - m1;
    double result1[2][3] = {5, 4, 3, 2, 1, 0};
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result1[i][j], res(i, j));
    }
}