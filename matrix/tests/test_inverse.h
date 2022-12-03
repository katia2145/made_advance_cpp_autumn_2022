#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(MATRIX, TestInverse)
{
    Matrix m;
    m = {
        {1, 2, 3},
        {4, 5, 6}, 
        {7, 8, 9}};
    
    EXPECT_THROW({
        try
        {
            m.inverse();
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("determinat is 0, invers matrix dont exist", e.what());
            throw;
        }
    },
                 invalid_argument);

    m = {
        {1, 2, 3},
        {4, 5, 6}};

    EXPECT_THROW({
        try
        {
            m.inverse();
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("matrix must be square", e.what());
            throw;
        }
    },
                 invalid_argument);

    m = {
        {1, 2, -1},
        {5, 5, 6}, 
        {7, -5, 9}};
    double result[3][3] = {75.0/129, -13.0/129, 17.0/129,
                           -3.0/129, 16.0/129, -11.0/129,
                           -60.0/129, 19.0/129, -5.0/129,};

    Matrix res;
    res = m.inverse();
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 3);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }
}
