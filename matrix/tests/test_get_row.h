#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(MATRIX, TestGetRow)
{
    Matrix m;
    m = Matrix(5, 3);

    for(int i = 0; i < 5; ++i){
        auto res = m.get_row(i);
        for(int j = 0; j < 3; ++j){
            EXPECT_DOUBLE_EQ(0.0, res[j]);
        }
    }

    EXPECT_THROW({
        try
        {
            m.get_row(-1);
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
            m.get_row(5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(VECTOR, TestGetRow)
{
    Custom_vector v;
    v = {1, 2, 3, 4};
    v.transpouse();
    double result[] = {1, 2, 3, 4};

    for(int i = 0; i < 4; ++i){
        auto res = v.get_row(i);
        EXPECT_DOUBLE_EQ(result[i], res[0]);
    }

    EXPECT_THROW({
        try
        {
            v.get_row(-1);
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
            v.get_row(4);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    v = {1, 2, 3, 4};

    auto res1 = v.get_row(0);
    for(int i = 0; i < 4; ++i){
        EXPECT_DOUBLE_EQ(result[i], res1[i]);
    }

    EXPECT_THROW({
        try
        {
            v.get_row(1);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}
