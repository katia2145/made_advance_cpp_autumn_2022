#include "Custom_vector.h"

#ifndef MATRIX_H
#define MATRIX_H

class Matrix : public Custom_vector{
public:
    double **matrix;
    
    Matrix(int cnt_rows = 2, int cnt_columns = 2) {
        if(cnt_columns < 1 || cnt_rows < 1){
            throw invalid_argument("size must be > 0");
        }
        this->cnt_rows = cnt_rows;
        this->cnt_columns = cnt_columns;
        this->matrix = new double *[cnt_rows];

        for(int i = 0; i < cnt_rows; ++i){
            this->matrix[i] = new double[cnt_columns];
            for(int j = 0; j < cnt_columns; ++j){
                this->matrix[i][j] = 0.0;
            }
        }
    }

    Matrix(Custom_vector* vectors) {
        int n = sizeof(vectors) / sizeof(Custom_vector);
        int cnt_rows = n;
        int cnt_columns = 0;
        double **cur_matrix = new double *[n];

        for(int i = 0; i < n; ++i){
            if(i == 0){
                cnt_columns = vectors[i].cnt_columns;
                cnt_rows = vectors[i].cnt_rows;
            }
            else if(vectors[i].cnt_columns != cnt_columns || \
                    vectors[i].cnt_rows != cnt_rows){
                    throw invalid_argument("cnt_columns and cnt_rows of vectors must be same");
            }
            cur_matrix[i] = new double[cnt_columns];
            for(int j = 0; j < cnt_columns; ++j){
                cur_matrix[i][j] = vectors[i](j);
            }
        }

        this->matrix = cur_matrix;
        this->cnt_columns = cnt_columns;
        this->cnt_rows = cnt_rows;
    }

    Matrix operator=(initializer_list<initializer_list<double>> mtx)
    {
        this->cnt_rows = mtx.size();
        this->matrix = new double *[this->cnt_rows];

        int i = 0;
        for (auto row : mtx){
            if(i == 0){
                this->cnt_columns = row.size();
            }
            copy(row.begin(), row.end(), this->matrix[i++]);
        }
    }

    double& operator()(int i, int j);
    
    double* get_row(int i);

    double* get_column(int j);

    double* get_diagonal(string diag_type = "main");
};

#endif