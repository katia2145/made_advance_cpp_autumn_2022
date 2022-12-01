#include "Custom_vector.h"

#include <bits/stdc++.h>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix : public Custom_vector
{
public:
    double **matrix;

    Matrix(int cnt_rows = 2, int cnt_columns = 2)
    {
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

    Matrix operator-(Matrix mtx);

    Matrix operator*(Matrix mtx);

    Matrix operator*(double num);

    double &operator()(int i, int j);

    double *get_row(int i);

    double *get_column(int j);

    double *get_diagonal(string diag_type = "main");
};

// inline Matrix operator*(double num, Matrix mtx);

// inline Matrix operator*(Matrix mtx, double num);

inline Custom_vector operator*(Custom_vector vect, Matrix mtx);

#endif