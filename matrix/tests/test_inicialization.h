#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(MATRIX, TestInicialization)
{
    Matrix m = Matrix(5, 3);
    EXPECT_EQ(5, m.cnt_rows);
    EXPECT_EQ(3, m.cnt_columns);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            EXPECT_DOUBLE_EQ(0.0, m(i, j));
        }
    }

    m = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(2, m.cnt_rows);
    EXPECT_EQ(3, m.cnt_columns);

    double result[2][3] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            EXPECT_DOUBLE_EQ(result[i][j], m(i, j));
        }
    }

    Custom_vector v1, v2, v3;
    v1 = {1, 2, 3};
    v2 = {4, 5, 6};
    v3 = {7, 8};

    Custom_vector v[] = {v1, v2};
    m = Matrix(v, 2, 3);
    EXPECT_EQ(2, m.cnt_rows);
    EXPECT_EQ(3, m.cnt_columns);

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            EXPECT_DOUBLE_EQ(result[i][j], m(i, j));
        }
    }

    Custom_vector v_err[] = {v1, v2, v3};
    EXPECT_THROW({
        try
        {
            m = Matrix(v_err, 3, 3);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("cnt_columns and cnt_rows of vectors must be same", e.what());
            throw;
        }
    },
                 invalid_argument);

    v1.transpouse();
    Custom_vector v_err1[] = {v1, v2};
    EXPECT_THROW({
        try
        {
            m = Matrix(v_err1, 3, 3);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("cnt_columns and cnt_rows of vectors must be same", e.what());
            throw;
        }
    },
                 invalid_argument);

    v2.transpouse();

    Custom_vector v_col[] = {v1, v2};
    m = Matrix(v_col, 3, 2);
    EXPECT_EQ(3, m.cnt_rows);
    EXPECT_EQ(2, m.cnt_columns);
    double result_col[3][2] = {1, 4, 2, 5, 3, 6};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
            EXPECT_DOUBLE_EQ(result_col[i][j], m(i, j));
    }
}
TEST(VECTOR, TestInicialization)
{
    Custom_vector v;

    v = Custom_vector(1, 5);
    EXPECT_EQ(1, v.cnt_rows);
    EXPECT_EQ(5, v.cnt_columns);

    for (int i = 0; i < 5; ++i)
        EXPECT_DOUBLE_EQ(0.0, v(i));

    v = Custom_vector(5, 1);
    EXPECT_EQ(5, v.cnt_rows);
    EXPECT_EQ(1, v.cnt_columns);

    for (int i = 0; i < 5; ++i)
        EXPECT_DOUBLE_EQ(0.0, v(i));

    v = {1, 2, 3};
    EXPECT_EQ(1, v.cnt_rows);
    EXPECT_EQ(3, v.cnt_columns);

    double result[] = {1, 2, 3};
    for (int i = 0; i < 3; ++i)
        EXPECT_DOUBLE_EQ(result[i], v(i));
}