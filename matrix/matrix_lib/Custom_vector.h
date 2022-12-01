#include <stdexcept>
using namespace std;

#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

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

    double &operator()(int i);

    double &operator()(int i, int j);

    double *get_row(int i);

    double *get_column(int j);

    Custom_vector transpouse();

private:
    double *get_row_column(int i, int cnt);
};

#endif