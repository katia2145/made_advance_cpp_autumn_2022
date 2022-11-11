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

    double& operator()(int i, int j);
    
    double* get_row(int i);

    double* get_column(int j);

    double* get_diagonal(string diag_type = "main");
};

#endif