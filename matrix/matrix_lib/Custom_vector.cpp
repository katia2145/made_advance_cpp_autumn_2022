#include "Custom_vector.h"
#include <stdexcept>

#include <bits/stdc++.h>
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

Custom_vector Custom_vector::operator+(Custom_vector vect){
    if(this->cnt_rows != vect.cnt_rows || this->cnt_columns != vect.cnt_columns){    
        throw invalid_argument("vectors must be same dimentions");
    }

    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);
    for(int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i){
        res.array[i] = this->array[i] + vect.array[i];
    }

    res.cnt_columns = this->cnt_columns;
    res.cnt_rows = this->cnt_rows;
    return res;
}

Custom_vector Custom_vector::operator-(Custom_vector vect){
    if(this->cnt_rows != vect.cnt_rows || this->cnt_columns != vect.cnt_columns){    
        throw invalid_argument("vectors must be same dimentions");
    }

    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);
    for(int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i){
        res.array[i] = this->array[i] - vect.array[i];
    }

    res.cnt_columns = this->cnt_columns;
    res.cnt_rows = this->cnt_rows;
    return res;
}

Custom_vector Custom_vector::operator*(Custom_vector vect){
    if(this->cnt_rows != vect.cnt_rows || this->cnt_columns != vect.cnt_columns){    
        throw invalid_argument("vectors must be same dimentions");
    }

    Custom_vector res = Custom_vector(this->cnt_rows, this->cnt_columns);
    for(int i = 0; i < max(this->cnt_rows, this->cnt_columns); ++i){
        res.array[i] = this->array[i] * vect.array[i];
    }

    res.cnt_columns = this->cnt_columns;
    res.cnt_rows = this->cnt_rows;
    return res;
}

double* Custom_vector::get_row(int i){
    if(this->cnt_rows == 0 || i < 0 || this->cnt_rows <= i){    
        throw invalid_argument("index out of range");
    }
    return Custom_vector::get_row_column(i, this->cnt_columns);
}

double* Custom_vector::get_column(int j){
    if(this->cnt_columns == 0 || j < 0 || this->cnt_columns <= j){    
        throw invalid_argument("index out of range");
    }
    return Custom_vector::get_row_column(j, this->cnt_rows);
}

double* Custom_vector::get_row_column(int i, int cnt){
    if(cnt != 1){
        double* row = new double[cnt];
        for(int i = 0; i < cnt; ++i){
            row[i] = this->array[i];
        }
        return row;
    }
    else{
        double* row = new double[1];
        row[0] = this->array[i];
        return row;
    }
}

Custom_vector Custom_vector::transpouse(){
    int cnt_columns = this->cnt_columns;
    this->cnt_columns = this->cnt_rows;
    this->cnt_rows = cnt_columns;
}