#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/Matrix.h"
#include "../matrix_lib/Custom_vector.h"
}

#include <bits/stdc++.h>
using namespace std;

TEST(MATRIX, TestGetDiagonal)
{
    Matrix m;
    m = {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}};

    double res_main[] = {1, 5, 9};
    double *result = m.get_diagonal("main");
    for (int i = 0; i < 3; ++i)
        EXPECT_DOUBLE_EQ(result[i], res_main[i]);

    double res_reverse[] = {3, 5, 7};
    result = m.get_diagonal("reverse");
    for (int i = 0; i < 3; ++i)
        EXPECT_DOUBLE_EQ(result[i], res_reverse[i]);

    EXPECT_THROW({
        try
        {
            m.get_diagonal("main1");
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("invalid type of diagonal, must be main or reverse", e.what());
            throw;
        }
    },
                 invalid_argument);

    m = {{1, 2, 3},
         {4, 5, 6}};

    EXPECT_THROW({
        try
        {
            m.get_diagonal("main");
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("the number of rows must be equal to the number of columns", e.what());
            throw;
        }
    },
                 invalid_argument);
}
