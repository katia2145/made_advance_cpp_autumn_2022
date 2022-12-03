#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(MATRIX, TestMatrix)
{
    Matrix m;
    m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    EXPECT_EQ(m.determinat(), 0);

    m = {
        {1, 2, 3, 4},
        {7, 2, 3, 4},
        {1, 2, 5, 4},
        {1, 2, 3, 19}};

    EXPECT_EQ(m.determinat(), -360);

    m = {
        {1, 2, 3, 4},
        {7, 2, 3, 4},
        {1, 2, 5, 4}};

    EXPECT_THROW({
        try
        {
            m.determinat();
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("matrix must be square", e.what());
            throw;
        }
    },
                 invalid_argument);
}
