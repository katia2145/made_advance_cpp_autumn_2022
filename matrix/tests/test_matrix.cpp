#include <gtest/gtest.h>

using namespace std;

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
}

TEST(MATRIX, TestGetRow)
{
    Matrix m;
    m = Matrix(5, 3);

    // TODO: написать проверку размера массива
    for(int i = 0; i < 5; ++i){
        auto res = m.get_row(i);
        // EXPECT_EQ(3, sizeof(res) / sizeof(double));
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

TEST(MATRIX, TestGetColumn)
{
    Matrix v;
    v = Matrix(5, 3);

    // TODO: написать проверку размера массива
    for(int j = 0; j < 3; ++j){
        auto res = v.get_column(j);
        // EXPECT_EQ(5, sizeof(res) / sizeof(double));
        for(int i = 0; i < 5; ++i){
            EXPECT_DOUBLE_EQ(0.0, res[i]);
        }
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
            v.get_column(3);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(MATRIX, TestGetDiagonal)
{
    Matrix m;
    m = Matrix(5, 3);

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
    
    m = Matrix(5, 5);
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
    
    // TODO: написать проверку двух диагоналей
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

TEST(VECTOR, TestInicialization)
{
    Custom_vector v;
    
    v = Custom_vector(1, 5);
    EXPECT_EQ(1, v.cnt_rows);
    EXPECT_EQ(5, v.cnt_columns);

    for (int i = 0; i < 5; ++i)
    {
        EXPECT_DOUBLE_EQ(0.0, v(i));
    }

    v = Custom_vector(5, 1);
    EXPECT_EQ(5, v.cnt_rows);
    EXPECT_EQ(1, v.cnt_columns);

    for (int i = 0; i < 5; ++i)
    {
        EXPECT_DOUBLE_EQ(0.0, v(i));
    }
}

TEST(VECTOR, TestGetRow)
{
    Custom_vector v;
    v = Custom_vector(5, 1);

    for(int i = 0; i < 5; ++i){
        auto res = v.get_row(i);
        EXPECT_EQ(1, sizeof(res) / sizeof(double));
        EXPECT_DOUBLE_EQ(0.0, res[0]);
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
            v.get_row(5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    v = Custom_vector(1, 5);

    auto res1 = v.get_row(0);
    EXPECT_EQ(5, sizeof(res1) / sizeof(double));
    for(int i = 0; i < 5; ++i){
        EXPECT_DOUBLE_EQ(0.0, res1[i]);
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

TEST(VECTOR, TestGetColumn)
{
    Custom_vector v;
    v = Custom_vector(1, 5);

    auto res = v.get_column(0);
    EXPECT_EQ(1, sizeof(res) / sizeof(double));
    EXPECT_DOUBLE_EQ(0.0, res[0]);

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
            v.get_column(5);
        }
        catch (const invalid_argument &e)
        {
            EXPECT_STREQ("index out of range", e.what());
            throw;
        }
    },
                 invalid_argument);

    v = Custom_vector(5, 1);

    auto res1 = v.get_column(0);
    EXPECT_EQ(5, sizeof(res1) / sizeof(double));
    for(int i = 0; i < 5; ++i){
        EXPECT_DOUBLE_EQ(0.0, res1[i]);
    }

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
}