#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/Matrix.h"
#include "../matrix_lib/Custom_vector.h"
}

TEST(MATRIX, TestInvalidArgument)
{
    EXPECT_THROW({
        try
        {
            Matrix(-4, 5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("size must be > 0", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            Matrix(4, -5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("size must be > 0", e.what());
            throw;
        }
    },
                 invalid_argument);

    Matrix m = Matrix(5, 3);

    EXPECT_THROW({
        try
        {
            m(5, 0);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            m(-1, 0);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            m(0, 3);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            m(0, -1);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(VECTOR, TestInvalidArgument)
{
    EXPECT_THROW({
        try
        {
            Custom_vector(4, 5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("count columns or rows must be 1", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            Custom_vector(-4, 5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("size must be > 0", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            Custom_vector(4, -5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("size must be > 0", e.what());
            throw;
        }
    },
                 invalid_argument);

    Custom_vector v = Custom_vector(1, 5);
    EXPECT_THROW({
        try
        {
            v(-1);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            v(5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}