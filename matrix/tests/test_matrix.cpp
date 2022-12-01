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

    // m = {{1, 2, 3}, {4, 5, 6}};
    // EXPECT_EQ(2, m.cnt_rows);
    // EXPECT_EQ(3, m.cnt_columns);

    // double result[2][3] = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < 2; ++i)
    // {
    //     for (int j = 0; j < 3; ++j)
    //     {
    //         EXPECT_DOUBLE_EQ(result[i][j], m(i, j));
    //     }
    // }
    
    // Custom_vector v1, v2, v3;
    // v1 = {1, 2, 3};
    // v2 = {4, 5, 6};
    // v3 = {7, 8};

    // Custom_vector v[] = {v1, v2};
    // m = Matrix(v);
    // EXPECT_EQ(2, m.cnt_rows);
    // EXPECT_EQ(3, m.cnt_columns);

    // for (int i = 0; i < 2; ++i)
    // {
    //     for (int j = 0; j < 3; ++j)
    //     {
    //         EXPECT_DOUBLE_EQ(result[i][j], m(i, j));
    //     }
    // }

    // Custom_vector v_err[] = {v1, v2, v3};
    // EXPECT_THROW({
    //     try
    //     {
    //         m = Matrix(v_err);
    //     }
    //     catch (const invalid_argument &e)
    //     {
    //         EXPECT_STREQ("cnt_columns and cnt_rows of vectors must be same", e.what());
    //         throw;
    //     }
    // },
    //              invalid_argument);

    // v1 = v1.transpouse();
    // Custom_vector v_err1[] = {v1, v2};
    // EXPECT_THROW({
    //     try
    //     {
    //         m = Matrix(v_err1);
    //     }
    //     catch (const invalid_argument &e)
    //     {
    //         EXPECT_STREQ("cnt_columns and cnt_rows of vectors must be same", e.what());
    //         throw;
    //     }
    // },
    //              invalid_argument);
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
    Matrix m;
    m = Matrix(5, 3);
    cout << m.cnt_columns << " " << m.cnt_rows<< endl;

    // TODO: написать проверку размера массива
    for(int j = 0; j < 3; ++j){
        double* res = m.get_column(j);
        cout << sizeof(&res) << " " << &res[0] << endl;
        // EXPECT_EQ(5, sizeof(res) / sizeof(double));
        for(int i = 0; i < 5; ++i){
            double* cur = &res[i];
            cout << *cur << endl;
            EXPECT_DOUBLE_EQ(0.0, *cur);
        }
    }

    // EXPECT_THROW({
    //     try
    //     {
    //         v.get_column(-1);
    //     }
    //     catch (const invalid_argument &e)
    //     {
    //         EXPECT_STREQ("index out of range", e.what());
    //         throw;
    //     }
    // },
    //              invalid_argument);
    
    // EXPECT_THROW({
    //     try
    //     {
    //         v.get_column(3);
    //     }
    //     catch (const invalid_argument &e)
    //     {
    //         EXPECT_STREQ("index out of range", e.what());
    //         throw;
    //     }
    // },
    //              invalid_argument);
}

TEST(MATRIX, TestGetDiagonal)
{
    // Matrix m;
    // m = Matrix(5, 3);

    // EXPECT_THROW({
    //     try
    //     {
    //         m.get_diagonal("main");
    //     }
    //     catch (const invalid_argument &e)
    //     {
    //         EXPECT_STREQ("the number of rows must be equal to the number of columns", e.what());
    //         throw;
    //     }
    // },
    //              invalid_argument);
    
    // m = Matrix(5, 5);
    // EXPECT_THROW({
    //     try
    //     {
    //         m.get_diagonal("main1");
    //     }
    //     catch (const invalid_argument &e)
    //     {
    //         EXPECT_STREQ("invalid type of diagonal, must be main or reverse", e.what());
    //         throw;
    //     }
    // },
    //              invalid_argument);
    
    // // TODO: написать проверку двух диагоналей
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
        EXPECT_DOUBLE_EQ(0.0, v(i));

    // v = Custom_vector(5, 1);
    // EXPECT_EQ(5, v.cnt_rows);
    // EXPECT_EQ(1, v.cnt_columns);

    // for (int i = 0; i < 5; ++i)
    //     EXPECT_DOUBLE_EQ(0.0, v(i));

    // v = {1.0, 2.0, 3.0};
    // EXPECT_EQ(1, v.cnt_rows);
    // EXPECT_EQ(3, v.cnt_columns);

    // double result[] = {1, 2, 3};
    // for (int i = 0; i < 5; ++i)
    //     EXPECT_DOUBLE_EQ(result[i], v(i));
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