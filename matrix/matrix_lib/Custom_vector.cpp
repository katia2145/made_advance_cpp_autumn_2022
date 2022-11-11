#include "Custom_vector.h"
#include <stdexcept>

double& Custom_vector::operator()(int i){
    if((this->cnt_rows != 1 && (i < 0 || this->cnt_rows <= i)) || \
       (this->cnt_columns != 1 && (i < 0 || this->cnt_columns <= i))){    
        throw invalid_argument("index out of range");
    }
    return this->array[i];
}

double* Custom_vector::get_row(int i){
    return Custom_vector::get_row_column(i, this->cnt_rows);
}

double* Custom_vector::get_column(int j){
    return Custom_vector::get_row_column(j, this->cnt_columns);
}

double* Custom_vector::get_row_column(int i, int cnt){
    if(cnt == 0 || (i < 0 || cnt <= i)){    
        throw invalid_argument("index out of range");
    }
    if(cnt != 1){
        double row[] = {this->array[i]};
        return row;
    }
    else{
        return this->array;
    }
}