// matrix.cpp

#include <iostream>
#include <iomanip>

#include "matrix.hpp"
#include "../myrandom/random.hpp"


namespace matrix {
    
    void FillMatrixWithRandomNumbers (int matrix[100][100], int row, int column) 
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                matrix[i][j] = myrandom::GetrandomNumberInRange(1, 100);
        }
    }
    void FillMatrixWithOrderNumbers (int matrix[100][100], int row, int column) 
    {
        int counter = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                counter++;
                matrix[i][j] = counter;
            }
        }
    
    }

    void FillTransposeMatrix (int matrix[100][100], int transpose_matrix[100][100], int row, int column) 
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                transpose_matrix[i][j] = matrix[j][i];
            }
            
        }
        
    }

    void PrintMatrix (int matrix[100][100], int row, int column) 
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                std::cout << std::setw(17) << std::left << matrix[i][j] << "  " ;
            }
            std::cout << std::endl;            
        }
        
    }
    
    void SumMatrixRowsIntoArray (int matrix[100][100], int result_array[], int row, int column)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                result_array[i] += matrix[i][j];
        }
    }
    
    void SumMatrixColumnsIntoArray (int matrix[100][100], int result_array[], int row, int column)
    {
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
                result_array[i] += matrix[j][i];
        }
    }
     
}