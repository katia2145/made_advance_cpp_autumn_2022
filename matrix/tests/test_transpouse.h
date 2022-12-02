#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(MATRIX, TestTranspouse)
{
    Matrix m1;
    m1 = {
        {1, 2, 3},
        {4, 5, 6}};
    double result[3][2] = {1, 2, 3, 4, 5, 6};

    Matrix res;
    res = res.transpouse();
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }
}

TEST(VECTOR, TestTranspouse)
{
    Custom_vector v;
    v = {1, 2, 3, 4};
    double result[4] = {1, 2, 3, 4};

    Custom_vector res = v.transpouse(); 
    EXPECT_EQ(res.cnt_columns, 4);
    EXPECT_EQ(res.cnt_rows, 1);
    for (int i = 0; i < 2; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }
}