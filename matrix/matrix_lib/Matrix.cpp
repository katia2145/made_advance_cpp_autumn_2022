#include "Matrix.h"
#include "Custom_vector.h"

#include <bits/stdc++.h>
using namespace std;

double& Matrix::operator()(int i, int j){
    if(0 <= i && i < this->cnt_rows && \
       0 <= j && j < this->cnt_columns)
        return this->matrix[i][j];
    throw invalid_argument("index out of range");
}

double* Matrix::get_row(int i){
    if(i < 0 || this->cnt_rows <= i){
        throw invalid_argument("index out of range");
    }
    return this->matrix[i];
}

double* Matrix::get_column(int j){
    if(j < 0 || this->cnt_columns <= j){
        throw invalid_argument("index out of range");
    }
    
    double res[this->cnt_rows];
    for(int i = 0; i < this->cnt_rows; ++i){
        res[i] = this->matrix[i][j];
    }
    return res;
}

double*  Matrix::get_diagonal(string diag_type = "main"){
    if(this->cnt_rows != this->cnt_columns){
        throw invalid_argument("the number of rows must be equal to the number of columns");
    }
    if(diag_type != "main" && diag_type != "reverse"){
        throw invalid_argument("invalid type of diagonal, must be main or reverse");
    }

    double res[this->cnt_rows];

    if(diag_type == "main"){
        for(int i = 0; i < this->cnt_rows; ++i){
            res[i] = this->matrix[i][i];
        }
    }
    if(diag_type == "reverse"){
        for(int i = this->cnt_columns - 1; 0 <= i; --i){
            res[i] = this->matrix[i][i];
        }
    }
    return res;
}