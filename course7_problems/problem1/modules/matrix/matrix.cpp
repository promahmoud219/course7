// matrix.cpp

#include <iostream>
#include <iomanip>

#include "matrix.hpp"
#include "../myrandom/random.hpp"


namespace matrix {
    
    void FillMatrixArray (int matrix_array[100][100], int row, int column) 
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                matrix_array[i][j] = myrandom::GetrandomNumberInRange(1, 100);
        }
    }

    void PrintMatrixWithRandomNums (int matrix_array[100][100], int row, int column) 
    {
        std::cout << "\nThe following is a " << row << "x" << column << " random matrix:\n";
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                std::cout << std::setw(17) << std::left << matrix_array[i][j] << "  " ;
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
     
}