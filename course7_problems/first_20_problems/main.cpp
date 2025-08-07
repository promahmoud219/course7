// main.cpp


#include <iostream>

#include "matrix/matrix.hpp"
#include "array/array.hpp"
#include "inputvalidation/inputvalidation.hpp"

int main () 
{
    matrix::stMatrix mx1;

    mx1.rows = inputvalidation::ReadPositiveNumber("\nEnter Row:\n");
    mx1.cols = inputvalidation::ReadPositiveNumber("\nEnter Column:\n");
    
    matrix::FillMatrixWithRandomNumbers(mx1);
    std::cout << "\nThe following is a " << mx1.rows << "x" << mx1.cols << " random matrix \"matrix\":\n";
    matrix::PrintMatrix(mx1);

    int array[100];
    matrix::SumMatrixRowsIntoArray(mx1, array);
    array::PrintRowsSumArray(array, mx1.rows);
    
    int array2[100];
    matrix::SumMatrixColumnsIntoArray(mx1, array2);
    array::PrintColumnsSumArray(array2, mx1.cols);

    matrix::stMatrix mx2;
    matrix::FillMatrixWithOrderNumbers(mx2);
    std::cout << "\nThe following is a " << mx2.rows << "x" << mx2.cols << " ordered matrix\"matrix2\":\n";
    matrix::PrintMatrix(mx2);

    int transpos_matrix[100][100];
    matrix::stMatrix transpose_mx;

    matrix::GetTranspose()
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
        std::cout << "\nthey are equals\n";
    else
        std::cout << "\nthey are not equals\n";
 
        
    int matrix_by_user[100][100];
    matrix::FillMatrixByUser(matrix_by_user, row, column);
    if (matrix::IsIdentityMatrix(matrix_by_user, row, column))
        std::cout << "\nthis is an identity matrix\n";
    else    
        std::cout << "\nthis is not an identity matrix\n";    


    if (matrix::IsSparceMatrix(matrix_by_user, row, column))
        std::cout << "\nthis matrix \"matrix_by_user\" is sparce\n";
    else
        std::cout << "\nthis matrix \"matrix_by_user\" is not sparce\n";

    if (matrix::IsNumberFound(matrix_by_user, row, column, 10))
        std::cout << "\nnumber 10 is found in matrix_by_user: ";
    if (!matrix::IsNumberFound(matrix_by_user, row, column, 7))
        std::cout << "\nnumber 7 is notfound in matrix_by_user: ";
}
