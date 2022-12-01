#include "Custom_vector.h"
#include <stdexcept>
using namespace std;

double& Custom_vector::operator()(int i){
    if((this->cnt_rows != 1 && (i < 0 || this->cnt_rows <= i)) || \
       (this->cnt_columns != 1 && (i < 0 || this->cnt_columns <= i))){    
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

Custom_vector Custom_vector::transpouse(){
    swap(this->cnt_columns, this->cnt_rows);
}