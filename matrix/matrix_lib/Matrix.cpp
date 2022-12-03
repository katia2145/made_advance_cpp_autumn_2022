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

Matrix Matrix::add(Custom_vector vect, string addition_type)
{
    if (addition_type == "row")
    {
        if (vect.cnt_columns != this->cnt_columns)
        {
            throw invalid_argument("vector and matrix must have same cnt_columns");
        }
        Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
        for (int i = 0; i < this->cnt_rows; ++i)
        {
            for (int j = 0; j < this->cnt_columns; ++j)
            {
                m.matrix[i][j] = this->matrix[i][j] + vect(j);
            }
        }
        return m;
    }
    else if (addition_type == "column")
    {
        if (vect.cnt_columns != this->cnt_columns)
        {
            throw invalid_argument("vector and matrix must have same cnt_rows");
        }
        Matrix m = Matrix(this->cnt_rows, this->cnt_columns);
        for (int i = 0; i < this->cnt_rows; ++i)
        {
            for (int j = 0; j < this->cnt_columns; ++j)
            {
                m.matrix[i][j] = this->matrix[i][j] + vect(i);
            }
        }
        return m;
    }
    else
    {
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
    return mtx * (-1) + num;
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

Matrix Matrix::transpouse()
{
    Matrix m = Matrix(this->cnt_columns, this->cnt_rows);
    for (int i = 0; i < this->cnt_columns; ++i)
    {
        for (int j = 0; j < this->cnt_rows; ++j)
        {
            m.matrix[i][j] = this->matrix[j][i];
        }
    }
    return m;
}

double Matrix::determinat()
{
    if (this->cnt_columns != this->cnt_rows)
        throw invalid_argument("matrix must be square");

    if (this->cnt_columns == 2)
    {
        return this->matrix[0][0] * this->matrix[1][1] - this->matrix[1][0] * this->matrix[0][1];
    }

    double det = 0;

    for (int col = 0, one = 1; col < this->cnt_columns; ++col)
    {
        Matrix m = Matrix(this->cnt_rows - 1, this->cnt_columns - 1);

        for (int i = 1, new_i = 0; i < this->cnt_rows; ++i)
        {
            for (int j = 0, new_j = 0; j < this->cnt_columns; ++j)
            {
                if (j == col)
                {
                    continue;
                }
                m.matrix[new_i][new_j] = this->matrix[i][j];
                new_j++;
            }
            new_i++;
        }
        det += this->matrix[0][col] * one * m.determinat();
        one *= -1;
    }
    return det;
}

Matrix Matrix::inverse()
{
    double det = this->determinat();

    if (det < 1e-7)
        throw invalid_argument("determinat is 0, invers matrix dont exist");

    det = 1.0 / det;

    Matrix m_t = this->transpouse();
    Matrix m = Matrix(this->cnt_rows, this->cnt_columns);

    for (int i = 0; i < m.cnt_rows; ++i)
    {
        for (int j = 0; j < m.cnt_columns; ++j)
        {

            Matrix addtion_mtx = Matrix(m_t.cnt_rows - 1, m_t.cnt_columns - 1);
            for (int row = 0, new_row = 0; row < m_t.cnt_rows; ++row)
            {
                if (row == i)
                    continue;
                for (int col = 0, new_col = 0; col < m_t.cnt_columns; ++col)
                {
                    if (col == j)
                        continue;
                    addtion_mtx.matrix[new_row][new_col] = this->matrix[row][col];
                    new_col++;
                }
                new_row++;
            }

            m.matrix[i][j] = pow(-1, i + j) * addtion_mtx.determinat();
            cout << m.matrix[i][j] << " ";
        }
    }

    return m.transpouse() * det;
}