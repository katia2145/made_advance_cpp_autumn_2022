#include <stdexcept>
using namespace std;

#include <bits/stdc++.h>

#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H

class Custom_vector;
class Matrix;

class Custom_vector
{
public:
    int cnt_rows;
    int cnt_columns;
    double *array;

    Custom_vector(int cnt_rows = 1, int cnt_columns = 3)
    {
        if (cnt_columns < 1 || cnt_rows < 1)
        {
            throw invalid_argument("size must be > 0");
        }
        if (cnt_columns != 1 && cnt_rows != 1)
        {
            throw invalid_argument("count columns or rows must be 1");
        }
        this->cnt_columns = cnt_columns;
        this->cnt_rows = cnt_rows;
        int n = max(cnt_rows, cnt_columns);
        this->array = new double[n];

        for (int i = 0; i < n; ++i)
        {
            this->array[i] = 0.0;
        }
    }

    Custom_vector operator=(initializer_list<double> vect);

    Custom_vector operator+(Custom_vector vect);

    Custom_vector operator+(double num);

    friend Custom_vector operator+(double const &num, Custom_vector mtx);

    friend Custom_vector operator+(int const &num, Custom_vector mtx);

    Matrix add(Matrix mtx, string addition_type);

    Custom_vector operator-(Custom_vector vect);

    Custom_vector operator-(double num);

    friend Custom_vector operator-(double const &num, Custom_vector mtx);

    friend Custom_vector operator-(int const &num, Custom_vector mtx);

    Custom_vector operator*(Custom_vector vect);

    Matrix operator*(Matrix mtx);

    double &operator()(int i);

    double &operator()(int i, int j);

    double *get_row(int i);

    double *get_column(int j);

    Custom_vector transpouse();

private:
    double *get_row_column(int i, int cnt);
};

class Matrix : public Custom_vector
{
public:
    double **matrix;

    Matrix(int cnt_rows = 2, int cnt_columns = 2)
    {
        // cout << "1111111111\n";
        if (cnt_columns < 1 || cnt_rows < 1)
        {
            throw invalid_argument("size must be > 0");
        }
        this->cnt_rows = cnt_rows;
        this->cnt_columns = cnt_columns;
        this->matrix = new double *[cnt_rows];

        for (int i = 0; i < cnt_rows; ++i)
        {
            this->matrix[i] = new double[cnt_columns];
            for (int j = 0; j < cnt_columns; ++j)
            {
                this->matrix[i][j] = 0.0;
            }
        }
    }

    Matrix(Custom_vector *vectors, int cnt_rows, int cnt_columns)
    {
        double **cur_matrix = new double *[cnt_rows];

        int vector_cnt_columns = vectors[0].cnt_columns;
        int vector_cnt_rows = vectors[0].cnt_rows;

        if (vector_cnt_rows == 1)
        {
            for (int i = 0; i < cnt_rows; ++i)
            {
                if (vectors[i].cnt_columns != vector_cnt_columns ||
                    vectors[i].cnt_rows != vector_cnt_rows)
                {
                    throw invalid_argument("cnt_columns and cnt_rows of vectors must be same");
                }
                cur_matrix[i] = new double[cnt_columns];
                for (int j = 0; j < cnt_columns; ++j)
                {
                    cur_matrix[i][j] = vectors[i](j);
                }
            }
        }
        else
        {
            for (int i = 0; i < cnt_rows; ++i)
            {
                cur_matrix[i] = new double[cnt_columns];
                for (int j = 0; j < cnt_columns; ++j)
                {
                    if (i == 0)
                    {
                        if (vectors[j].cnt_columns != vector_cnt_columns ||
                            vectors[j].cnt_rows != vector_cnt_rows)
                        {
                            throw invalid_argument("cnt_columns and cnt_rows of vectors must be same");
                        }
                    }
                    cur_matrix[i][j] = vectors[j](i);
                }
            }
        }

        this->matrix = cur_matrix;
        this->cnt_columns = cnt_columns;
        this->cnt_rows = cnt_rows;
    }

    Matrix operator=(initializer_list<initializer_list<double>> mtx);

    Matrix operator+(Matrix mtx);

    Matrix operator+(double num);

    friend Matrix operator+(double const &num, Matrix mtx);

    friend Matrix operator+(int const &num, Matrix mtx);

    Matrix add(Custom_vector vect, string addition_type);

    Matrix operator-(Matrix mtx);

    Matrix operator-(double num);

    friend Matrix operator-(double const &num, Matrix mtx);

    friend Matrix operator-(int const &num, Matrix mtx);

    Matrix operator*(Matrix mtx);

    Matrix operator*(double num);

    Matrix operator*(int num);

    friend Matrix operator*(double const &num, Matrix mtx);

    friend Matrix operator*(int const &num, Matrix mtx);

    Matrix operator*(Custom_vector vect);

    Matrix operator&(Matrix mtx);

    double &operator()(int i, int j);

    double *get_row(int i);

    double *get_column(int j);

    double *get_diagonal(string diag_type = "main");

    Matrix transpouse();

    double determinat();

    Matrix inverse();
};

#endif