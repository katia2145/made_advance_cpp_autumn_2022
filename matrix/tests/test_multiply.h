#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(VECTOR, TestMultiply)
{
    Custom_vector v1, v2;
    v1 = {1, 2, 3, 4};
    v2 = {1, 2, 3, 4};
    double result[] = {1, 4, 9, 16};

    Custom_vector res;
    res = v1 * v2;
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }

    v1.transpouse();

    EXPECT_THROW({
        try
        {
            v1 *v2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vectors must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);

    v2.transpouse();
    res = v1 * v2;
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

TEST(MATRIX, TestMultiplyByElement)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[2][3] = {1, 4, 9, 16, 25, 36};

    Matrix res;
    res = m1 * m1;
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
            m1 *m2;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("matrix must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(MATRIX, TestMultiplyByNumber)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[2][3] = {2, 4, 6, 8, 10, 12};

    Matrix res;
    res = m1 * 2;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    res = 2 * m1;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }
}

TEST(MATRIX, TestMultiplyByVector)
{
    Matrix m1;
    m1 = {
        {1, 4},
        {2, 5},
        {3, 6},
    };

    Custom_vector v;
    v = {1, 2, 3};
    double result[1][2] = {14, 32};

    Matrix res;
    res = v * m1;
    for (int i = 0; i < 1; ++i)
    {
        for (int j = 0; j < 2; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    EXPECT_THROW({
        try
        {
            m1 *v;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vector cnt_columns must be equal matrix cnt_rows", e.what());
            throw;
        }
    },
                 invalid_argument);

    v = {1, 2};
    EXPECT_THROW({
        try
        {
            m1 *v;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("vector cnt_columns must be equal matrix cnt_rows", e.what());
            throw;
        }
    },
                 invalid_argument);

    v.transpouse();
    double result1[3][1] = {9, 12, 15};
    res = m1 * v;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 1; ++j)
            EXPECT_DOUBLE_EQ(result1[i][j], res(i, j));
    }

    // cout << "ok\n";
    // m1 = {{1, 2, 3}};
    // v = {1, 2, 3};
    // v.transpouse();
    // double result2[3][3] = {1, 2, 3, 2, 4, 6, 3, 6, 9};
    // res = v * m1;
    // for (int i = 0; i < 3; ++i)
    // {
    //     for (int j = 0; j < 3; ++j)
    //         EXPECT_DOUBLE_EQ(result2[i][j], res(i, j));
    // }
}

TEST(MATRIX, TestMultiplyByMatrix)
{
    Matrix m1;
    m1 = {
        {1, 4},
        {2, 5},
        {3, 6}};

    Matrix m2;
    m2 = {
        {1, 4},
        {2, 5}};

    Matrix res;
    res = m1 & m2;
    double result[3][2] = {9, 24, 12, 33, 15, 42};

    for (int i = 0; i < 1; ++i)
    {
        for (int j = 0; j < 2; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    EXPECT_THROW({
        try
        {
            m2 &m1;
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("matrix must be same dimentions", e.what());
            throw;
        }
    },
                 invalid_argument);
}