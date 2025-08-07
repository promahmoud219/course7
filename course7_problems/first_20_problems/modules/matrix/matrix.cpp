// matrix.cpp

#include <iostream>
#include <iomanip>

#include "matrix.hpp"
#include "../myrandom/random.hpp"
#include "../inputvalidation/inputvalidation.hpp"


namespace matrix {
    
    bool IsNumberFound (int matrix[100][100], int row, int column, int number_to_found)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (matrix[i][j] == number_to_found)
                    return true;
            }
        }
        return false;
    }

    bool IsSparceMatrix (int matrix[100][100], int row, int column)
    {
        int matrix_size = row*column;
        return (CountNumberInMatrix(matrix, row, column, 0) >= (matrix_size/2));
    }

    int CountNumberInMatrix (int matrix[100][100], int row, int column, int number_to_count)
    {
        int counter = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (matrix[i][j] == number_to_count)
                    counter++;
            }
        }
        return counter;        
    }

    bool IsIdentityMatrix (int matrix[100][100], int row, int column)
    {
        if (row != column)
            return false;  // Identity matrix must be square
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {   
                //! beginner solution 

                // if (i==j)  
                // {
                //     if (matrix[i][j] != 1)
                //         return false;
                // }
                // else  
                // {
                //     if (matrix[i][j] != 0)
                //         return false;                    
                // }

                if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                    return false;

            }
        }
        return true;
    }
    
    bool IsScalarMatrix (int matrix[100][100], int row, int column)
    {
        int first_index = matrix[0][0];

        if (row != column)
            return false;  // Identity matrix must be square
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {   
                if ((i == j && matrix[i][j] != first_index) || (i != j && matrix[i][j] != 0))
                    return false;

                }
            }
            return true;
    }
    
    void FillMatrixByUser (int matrix[100][100], int row, int column)
    {
        std::string message = "";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                message = "please enter number " + std::to_string(i+1) + "*" + std::to_string(j+1) + "\n"; 
                matrix[i][j] = inputvalidation::ReadPositiveNumber(message);
            }

        }

    }

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
    
    int SumOfMatrix (int matrix[100][100], int row, int column) 
    {
        int counter = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                counter += matrix[i][j];
        }
        return counter;
    }

    void MiddleRow (int matrix[100][100], int array[100], int row, int column) 
    {
        
        for (int i = 0; i < row; i++)
        {
            if ((row /2) == i)
            {
                for (int j = 0; j < column; j++)
                {
                    array[j] = matrix[i][j];
                }
            }
        }
    }

    void FillTransposeMatrix (int matrix[100][100], int transpose_matrix[100][100], int row, int column) 
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                transpose_matrix[j][i] = matrix[i][j];
            }
            
        }
        
    }

    void MultiplyTwoMatrices (int matrix1[100][100], int matrix2[100][100], int  empty_matrix[100][100], int row, int column) 
    {
        for (int i = 0;i < row;i++)
        {
            for (int j = 0; j < column; j++)
            {
                empty_matrix[i][j] = matrix1[i][j] * matrix2[i][j];
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
     
    bool AreMatricesEqual (int matrix1[100][100], int matrix2[100][100], int row, int column)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (matrix1[i][j] != matrix2[i][j])
                    return false;
            }
        }
        return true;        
    }
    
    void CopyMatrix (int matrix[100][100], int empty_matrix[100][100], int row, int column)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                empty_matrix[i][j] = matrix[i][j];
        }
    }

    
}