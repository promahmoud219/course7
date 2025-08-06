// main.cpp


#include <iostream>

#include "matrix/matrix.hpp"
#include "array/array.hpp"
#include "inputvalidation/inputvalidation.hpp"

int main () 
{
    int matrix[100][100];
    int row = inputvalidation::ReadPositiveNumber("\nEnter Row:\n");
    int column = inputvalidation::ReadPositiveNumber("\nEnter Column:\n");
    
    matrix::FillMatrixWithRandomNumbers(matrix, row, column);
    std::cout << "\nThe following is a " << row << "x" << column << " random matrix \"matrix\":\n";
    matrix::PrintMatrix(matrix, row, column);

    int array[100];
    matrix::SumMatrixRowsIntoArray(matrix, array, row, column);
    array::PrintRowsSumArray(array, row);
    
    int array2[100];
    matrix::SumMatrixColumnsIntoArray(matrix, array2,  row, column);
    array::PrintColumnsSumArray(array2, column);

    int matrix3[100][100];
    matrix::FillMatrixWithOrderNumbers(matrix3, row, column);
    std::cout << "\nThe following is a " << row << "x" << column << " ordered matrix\"matrix3\":\n";
    matrix::PrintMatrix(matrix3, row, column);

    int transpos_matrix[100][100];
    matrix::FillTransposeMatrix(matrix3, transpos_matrix, row, column);
    std::cout << "\n\nthis is the transpose matrix of matrix3:\n";
    matrix::PrintMatrix(transpos_matrix, column, row);

    int multiplied_matrix[100][100];
    matrix::MultiplyTwoMatrices(matrix, matrix3, multiplied_matrix, row, column);
    std::cout << "\nthis is the result of  multiply matrix with matrix3:\n";
    matrix::PrintMatrix(multiplied_matrix, row, column);

    std::cout << "\n\nthis is the middle row  of multiplied matrix\n";
    int middl_row_array[100];
    matrix::MiddleRow(multiplied_matrix, middl_row_array, row, column);
    array::PrintArray(middl_row_array, column);

    std::cout << "\nThis is the sum of matrix: " << matrix::SumOfMatrix(matrix, row, column) << std::endl;

    int empty_matrix[100][100];
    matrix::CopyMatrix(multiplied_matrix, empty_matrix, row, column);
    std::cout << "\n\nthis is empty matrix after being copied from multiplied matrix:\n";
    matrix::PrintMatrix(empty_matrix, row, column);
    
    if (matrix::AreMatricesEqual(multiplied_matrix, empty_matrix, row, column))
        std::cout << "\nthey are equals";
    else
        std::cout << "\nthey are not equals";
 
        
    

}