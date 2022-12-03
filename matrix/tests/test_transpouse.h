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
    double result[3][2] = {1, 4, 2, 5, 3, 6};

    Matrix res;
    res = m1.transpouse();
    EXPECT_EQ(res.cnt_columns, 2);
    EXPECT_EQ(res.cnt_rows, 3);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
            EXPECT_DOUBLE_EQ(result[i][j], res(i, j));
    }

    res = res.transpouse();  
    double result1[2][3] = {1, 2, 3, 4, 5, 6};  
    EXPECT_EQ(res.cnt_columns, 3);
    EXPECT_EQ(res.cnt_rows, 2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(result1[i][j], res(i, j));
    }
}

TEST(VECTOR, TestTranspouse)
{
    Custom_vector v;
    v = {1, 2, 3, 4};
    double result[4] = {1, 2, 3, 4};

    Custom_vector res = v.transpouse(); 
    EXPECT_EQ(res.cnt_columns, 1);
    EXPECT_EQ(res.cnt_rows, 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_DOUBLE_EQ(result[i], res(i));
    }
}