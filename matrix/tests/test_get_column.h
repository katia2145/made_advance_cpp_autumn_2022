#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/lib.h"
}

TEST(MATRIX, TestGetColumn)
{
    Matrix m;
    m = Matrix(5, 3);

    for(int j = 0; j < 3; ++j){
        double* res = m.get_column(j);
        for(int i = 0; i < 5; ++i){
            EXPECT_DOUBLE_EQ(0.0, res[i]);
        }
    }

    EXPECT_THROW({
        try
        {
            m.get_column(-1);
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
            m.get_column(3);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(VECTOR, TestGetColumn)
{
    Custom_vector v;
    v = {1, 2, 3, 4};
    v = v.transpouse();
    double result[] = {1, 2, 3, 4};

    auto res = v.get_column(0);
    for(int i = 0; i < 4; ++i){
        EXPECT_DOUBLE_EQ(result[i], res[i]);
    }

    EXPECT_THROW({
        try
        {
            v.get_column(-1);
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
            v.get_column(1);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    v = {1, 2, 3, 4};

    for(int i = 0; i < 4; ++i){
        auto res1 = v.get_column(i);
        EXPECT_DOUBLE_EQ(result[i], res1[0]);
    }

    EXPECT_THROW({
        try
        {
            v.get_column(4);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}
