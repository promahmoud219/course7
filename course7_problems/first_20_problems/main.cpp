// main.cpp


#include <iostream>

#include "matrix/matrix.hpp"
#include "array/array.hpp"
#include "inputvalidation/inputvalidation.hpp"

int main () 
{
    int matrix_array[100][100];
    int row = inputvalidation::ReadPositiveNumber("\nEnter Row:\n");
    int column = inputvalidation::ReadPositiveNumber("\nEnter Column:\n");
    
    matrix::FillMatrixWithRandomNumbers(matrix_array, row, column);
    std::cout << "\nThe following is a " << row << "x" << column << " random matrix:\n";
    matrix::PrintMatrix(matrix_array, row, column);

    int matrix[100];
    matrix::SumMatrixRowsIntoArray(matrix_array, matrix, row, column);
    array::PrintRowsSumArray(matrix, row);
    
    int matrix2[100];
    matrix::SumMatrixColumnsIntoArray(matrix_array, matrix2,  row, column);
    array::PrintColumnsSumArray(matrix2, column);

    int matrix3[100][100];
    matrix::FillMatrixWithOrderNumbers(matrix3, row, column);
    std::cout << "\nThe following is a " << row << "x" << column << " ordered matrix:\n";
    matrix::PrintMatrix(matrix3, row, column);

    int transpos_matrix[100][100];
    matrix::FillTransposeMatrix(matrix3, transpos_matrix, row, column);
    std::cout << "\n\nthis is the transpose matrix of matrix3:\n";
    matrix::PrintMatrix(transpos_matrix, column, row);

}