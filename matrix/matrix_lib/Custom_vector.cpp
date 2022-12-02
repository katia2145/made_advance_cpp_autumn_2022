#include "lib.h"
#include <stdexcept>

#include <bits/stdc++.h>
using namespace std;

double &Custom_vector::operator()(int i)
{
    if ((this->cnt_rows != 1 && (i < 0 || this->cnt_rows <= i)) ||
        (this->cnt_columns != 1 && (i < 0 || this->cnt_columns <= i)))
    {
        throw invalid_argument("index out of range");
    }
    return this->array[i];
}

Custom_vector Custom_vector::operator=(initializer_list<double> vect)
{
    this->cnt_columns = vect.size();
    this->cnt_rows = 1;
    this->array = new double[this->cnt_columns];

    copy(vect.begin(), vect.end(), this->array);
}

Custom_vector Custom_vector::operator+(Custom_vector vect)
{
    if (this->cnt_rows != vect.cnt_rows || this->cnt_columns != vect.cnt_columns)
    {
        throw invalid_argument("vectors must be same dimentions");
    }

    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i)
    {
        res.array[i] = this->array[i] + vect.array[i];
    }
    return res;
}

Custom_vector Custom_vector::operator+(double num)
{
    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);

    for (int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i)
    {
        res.array[i] = this->array[i] + num;
    }
    return res;
}

Custom_vector operator+(double const &num, Custom_vector vect)
{
    return vect + num;
}

Custom_vector operator+(int const &num, Custom_vector vect)
{
    return (vect + (double)num);
}

Matrix Custom_vector::add(Matrix mtx, string addition_type){
    if(addition_type == "row"){
        if(this->cnt_columns != mtx.cnt_columns){
            throw invalid_argument("vector and matrix must have same cnt_columns");
        }
        Matrix m = Matrix(mtx.cnt_rows, mtx.cnt_columns);  
        for(int i = 0; i < mtx.cnt_rows; ++i){
            for(int j = 0; j < mtx.cnt_columns; ++j){
                m.matrix[i][j] = mtx(i, j) + this->array[j];
            }
        }
        return m;
    }
    else if(addition_type == "column"){
        if(this->cnt_columns != mtx.cnt_columns){
            throw invalid_argument("vector and matrix must have same cnt_rows");
        }
        Matrix m = Matrix(mtx.cnt_rows, mtx.cnt_columns);
        for(int i = 0; i < mtx.cnt_rows; ++i){
            for(int j = 0; j < mtx.cnt_columns; ++j){
                m.matrix[i][j] = mtx(i, j) + this->array[i];
            }
        }
        return m;
    }
    else{
        throw invalid_argument("no such type of addition, choose: row or column");
    }
}

Custom_vector Custom_vector::operator-(Custom_vector vect)
{
    if (this->cnt_rows != vect.cnt_rows || this->cnt_columns != vect.cnt_columns)
    {
        throw invalid_argument("vectors must be same dimentions");
    }

    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i)
    {
        res.array[i] = this->array[i] - vect.array[i];
    }

    res.cnt_columns = this->cnt_columns;
    res.cnt_rows = this->cnt_rows;
    return res;
}

Custom_vector Custom_vector::operator-(double num)
{
    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);

    for (int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i)
    {
        res.array[i] = this->array[i] - num;
    }

    return res;
}

Custom_vector operator-(double const &num, Custom_vector vect)
{
    Custom_vector res = Custom_vector(vect.cnt_rows, vect.cnt_columns);

    for (int i = 0; i < max(vect.cnt_rows, vect.cnt_columns); ++i)
    {
        res.array[i] = num - vect.array[i];
    }

    return res;
}

Custom_vector operator-(int const &num, Custom_vector vect)
{
    return ((double)num - vect);
}

Custom_vector Custom_vector::operator*(Custom_vector vect)
{
    if (this->cnt_rows != vect.cnt_rows || this->cnt_columns != vect.cnt_columns)
    {
        throw invalid_argument("vectors must be same dimentions");
    }

    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);
    for (int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i)
    {
        res.array[i] = this->array[i] * vect.array[i];
    }

    res.cnt_columns = this->cnt_columns;
    res.cnt_rows = this->cnt_rows;
    return res;
}

Matrix Custom_vector::operator*(Matrix mtx)
{
    if (this->cnt_columns != mtx.cnt_rows)
        throw invalid_argument("vector cnt_columns must be equal matrix cnt_rows");

    Matrix m = Matrix(this->cnt_rows, mtx.cnt_columns);

    for (int row = 0; row < this->cnt_rows; ++row)
    {
        for (int col = 0; col < mtx.cnt_columns; ++col)
        {
            for (int i = 0; i < this->cnt_columns; ++i)
            {
                // cout << this->array[i] << " * " << mtx(i, col) << " + ";
                m.matrix[row][col] += this->array[i] * mtx(i, col);
            }
            // cout << endl;
        }
    }

    return m;
}

double *Custom_vector::get_row(int i)
{
    if (this->cnt_rows == 0 || i < 0 || this->cnt_rows <= i)
    {
        throw invalid_argument("index out of range");
    }
    return Custom_vector::get_row_column(i, this->cnt_columns);
}

double *Custom_vector::get_column(int j)
{
    if (this->cnt_columns == 0 || j < 0 || this->cnt_columns <= j)
    {
        throw invalid_argument("index out of range");
    }
    return Custom_vector::get_row_column(j, this->cnt_rows);
}

double *Custom_vector::get_row_column(int i, int cnt)
{
    if (cnt != 1)
    {
        double *row = new double[cnt];
        for (int i = 0; i < cnt; ++i)
        {
            row[i] = this->array[i];
        }
        return row;
    }
    else
    {
        double *row = new double[1];
        row[0] = this->array[i];
        return row;
    }
}

Custom_vector Custom_vector::transpouse()
{
    Custom_vector v = Custom_vector(this->cnt_columns, this->cnt_rows);
    v.array = this->array;
    return v;
}