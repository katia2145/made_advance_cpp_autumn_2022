#include "Matrix.h"
#include "Custom_vector.h"

#include <bits/stdc++.h>
using namespace std;

Matrix Matrix::operator=(initializer_list<initializer_list<double>> mtx)
{
    this->cnt_rows = mtx.size();
    this->matrix = new double *[this->cnt_rows];

    int i = 0;
    for (auto row : mtx)
    {
        if (i == 0)
        {
            this->cnt_columns = row.size();
        }
        this->matrix[i] = new double[this->cnt_columns];
        copy(row.begin(), row.end(), this->matrix[i++]);
    }
}

double &Matrix::operator()(int i, int j)
{
    if (0 <= i && i < this->cnt_rows &&
        0 <= j && j < this->cnt_columns)
        return this->matrix[i][j];
    throw invalid_argument("index out of range");
}

Matrix Matrix::operator+(Matrix mtx)
{
    if (this->cnt_rows != mtx.cnt_rows || this->cnt_columns != mtx.cnt_columns)
    {
        throw invalid_argument("matrix must be same dimentions");
    }

    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < this->cnt_rows; ++i)
    {
        for (int j = 0; j < this->cnt_columns; ++j)
        {
            m.matrix[i][j] = this->matrix[i][j] + mtx(i, j);
        }
    }
    return m;
}

Matrix Matrix::operator-(Matrix mtx)
{
    if (this->cnt_rows != mtx.cnt_rows || this->cnt_columns != mtx.cnt_columns)
    {
        throw invalid_argument("matrix must be same dimentions");
    }

    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < this->cnt_rows; ++i)
    {
        for (int j = 0; j < this->cnt_columns; ++j)
        {
            m.matrix[i][j] = this->matrix[i][j] - mtx(i, j);
        }
    }
    return m;
}

Matrix Matrix::operator*(Matrix mtx)
{
    if (this->cnt_rows != mtx.cnt_rows || this->cnt_columns != mtx.cnt_columns)
    {
        throw invalid_argument("matrix must be same dimentions");
    }

    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < this->cnt_rows; ++i)
    {
        for (int j = 0; j < this->cnt_columns; ++j)
        {
            m.matrix[i][j] = this->matrix[i][j] * mtx(i, j);
        }
    }
    return m;
}

Matrix Matrix::operator*(double num)
{
    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);

    for (int i = 0; i < this->cnt_rows; ++i)
    {
        for (int j = 0; j < this->cnt_columns; ++j)
        {
            m.matrix[i][j] = this->matrix[i][j] * num;
        }
    }

    return m;
}

double *Matrix::get_row(int i)
{
    if (i < 0 || this->cnt_rows <= i)
    {
        throw invalid_argument("index out of range");
    }
    return this->matrix[i];
}

double *Matrix::get_column(int j)
{
    if (j < 0 || this->cnt_columns <= j)
    {
        throw invalid_argument("index out of range");
    }

    double *res = new double[this->cnt_rows];
    for (int i = 0; i < this->cnt_rows; ++i)
    {
        res[i] = this->matrix[i][j];
    }
    return res;
}

double *Matrix::get_diagonal(string diag_type)
{
    if (this->cnt_rows != this->cnt_columns)
    {
        throw invalid_argument("the number of rows must be equal to the number of columns");
    }
    if (diag_type != "main" && diag_type != "reverse")
    {
        throw invalid_argument("invalid type of diagonal, must be main or reverse");
    }

    double *res = new double[this->cnt_rows];

    if (diag_type == "main")
    {
        for (int i = 0; i < this->cnt_rows; ++i)
        {
            res[i] = this->matrix[i][i];
        }
    }
    if (diag_type == "reverse")
    {
        for (int i = this->cnt_columns - 1, j = 0; 0 <= i; --i, ++j)
        {
            res[i] = this->matrix[i][j];
        }
    }
    return res;
}

// inline Matrix operator*(Matrix mtx, double num)
// {
//     return num * mtx;
//     // Matrix m = Matrix(mtx.cnt_rows, mtx.cnt_columns);

//     // for (int i = 0; i < mtx.cnt_rows; ++i)
//     // {
//     //     for (int j = 0; j < mtx.cnt_columns; ++j)
//     //     {
//     //         m.matrix[i][j] = mtx(i, j) * num;
//     //     }
//     // }

//     // return m;
// }

inline Custom_vector operator*(Custom_vector vect, Matrix mtx)
{
    if (vect.cnt_columns != mtx.cnt_rows)
    {
        throw invalid_argument("vector cnt_columns must be equal matrix cnt_rows");
    }

    Custom_vector v;
    if (vect.cnt_columns != 1)
        v = Custom_vector(1, mtx.cnt_columns);
    else
        v = Custom_vector(mtx.cnt_columns, 1);

    for (int row = 0; row < vect.cnt_rows; ++row)
    {
        double cur_sum = 0;
        for (int i = 0; i < vect.cnt_columns; ++i)
        {
            cur_sum += vect(i) * mtx(i, row);
        }
        v.array[row] = cur_sum;
    }

    return v;
}