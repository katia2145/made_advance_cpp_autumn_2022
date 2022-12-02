#include "lib.h"

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

Matrix Matrix::operator+(double num)
{
    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < this->cnt_rows; ++i)
    {
        for (int j = 0; j < this->cnt_columns; ++j)
        {
            m.matrix[i][j] = this->matrix[i][j] + num;
        }
    }
    return m;
}

Matrix operator+(double const &num, Matrix mtx)
{
    return mtx + num;
}

Matrix operator+(int const &num, Matrix mtx)
{
    return mtx + (double)num;
}

Matrix Matrix::add(Custom_vector vect, string addition_type){
    if(addition_type == "row"){
        if(vect.cnt_columns != this->cnt_columns){
            throw invalid_argument("vector and matrix must have same cnt_columns");
        }
        Matrix m = Matrix(this->cnt_rows, this->cnt_columns);  
        for(int i = 0; i < this->cnt_rows; ++i){
            for(int j = 0; j < this->cnt_columns; ++j){
                m.matrix[i][j] = this->matrix[i][j] + vect(j);
            }
        }
        return m;
    }
    else if(addition_type == "column"){
        if(vect.cnt_columns != this->cnt_columns){
            throw invalid_argument("vector and matrix must have same cnt_rows");
        }
        Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
        for(int i = 0; i < this->cnt_rows; ++i){
            for(int j = 0; j < this->cnt_columns; ++j){
                m.matrix[i][j] = this->matrix[i][j] + vect(i);
            }
        }
        return m;
    }
    else{
        throw invalid_argument("no such type of addition, choose: row or column");
    }
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

Matrix operator-(double const &num, Matrix mtx)
{
    return mtx* (-1) + num;
}

Matrix operator-(int const &num, Matrix mtx)
{
    return mtx * (-1) + (double)num;
}

Matrix Matrix::operator-(double num)
{
    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < this->cnt_rows; ++i)
    {
        for (int j = 0; j < this->cnt_columns; ++j)
        {
            m.matrix[i][j] = this->matrix[i][j] - num;
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

Matrix Matrix::operator*(Custom_vector vect)
{
    if (this->cnt_columns != vect.cnt_rows)
        throw invalid_argument("vector cnt_columns must be equal matrix cnt_rows");

    Matrix m = Matrix(this->cnt_rows, vect.cnt_columns);

    for (int row = 0; row < this->cnt_rows; ++row)
    {
        for (int col = 0; col < vect.cnt_columns; ++col)
        {
            for (int i = 0; i < this->cnt_columns; ++i)
            {
                m.matrix[row][col] += this->matrix[row][i] * vect(i);
            }
        }
    }

    return m;
}

Matrix Matrix::operator&(Matrix mtx)
{
    if (this->cnt_columns != mtx.cnt_rows)
        throw invalid_argument("matrix must be same dimentions");

    Matrix m = Matrix(this->cnt_rows, mtx.cnt_columns);

    for (int row = 0; row < this->cnt_rows; ++row)
    {
        for (int col = 0; col < mtx.cnt_columns; ++col)
        {
            for (int i = 0; i < this->cnt_columns; ++i)
            {
                m.matrix[row][col] += this->matrix[row][i] * mtx(i, col);
            }
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

Matrix Matrix::operator*(int num)
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

Matrix operator*(double const &num, Matrix mtx)
{
    Matrix m = Matrix(mtx.cnt_rows, mtx.cnt_columns);

    for (int i = 0; i < mtx.cnt_rows; ++i)
    {
        for (int j = 0; j < mtx.cnt_columns; ++j)
        {
            m.matrix[i][j] = mtx.matrix[i][j] * num;
        }
    }

    return m;
}

Matrix operator*(int const &num, Matrix mtx)
{
    return mtx * num;
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


Matrix Matrix::transpouse(){
    Matrix m = Matrix(this->cnt_columns, this->cnt_rows);
    for(int i = 0; i < this->cnt_columns; ++i){
        for(int j = 0; j < this->cnt_rows; ++j){
            m.matrix[i][j] = this->matrix[j][i];
        }
    }
    return m;
}