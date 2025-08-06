// main.cpp


#include <iostream>

#include "matrix/matrix.hpp"
#include "array/array.hpp"

int main () 
{
    int matrix_array[100][100];
    int row = 4, column = 4;
    matrix::FillMatrixArray(matrix_array, row, column);
    matrix::PrintMatrixWithRandomNums(matrix_array, row, column);

    int array[100];
    matrix::SumMatrixRowsIntoArray(matrix_array, array, row, column);
    array::PrintRowsSumArray(array, row);
}