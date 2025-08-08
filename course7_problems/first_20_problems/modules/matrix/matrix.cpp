// matrix.cpp

#include <iostream>
#include <iomanip>

#include "matrix.hpp"
#include "../myrandom/random.hpp"
#include "../array/array.hpp"
#include "../inputvalidation/inputvalidation.hpp"

namespace matrix {

    bool AreMatricesEqual(const stMatrix& mx1, const stMatrix& mx2) {
        if (mx1.rows != mx2.rows || mx1.cols != mx2.cols)
            return false;

        for (int i = 0; i < mx1.rows; i++) {
            for (int j = 0; j < mx1.cols; j++) {
                if (mx1.data[i][j] != mx2.data[i][j])
                    return false;
            }
        }
        return true;
    }

    
    void CopyMatrix (const stMatrix& source, stMatrix& empty_mx) 
    {
        for (int i = 0; i < source.rows; i++) {
            for (int j = 0; j < source.cols; j++) 
                empty_mx.data[i][j] = source.data[i][j];
        } 
    }

    int CountNumberInMatrix(const stMatrix& mx, int number_to_count) {
        int counter = 0;
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                if (mx.data[i][j] == number_to_count)
                    counter++;
            }
        }
        return counter;
    }

    
    void FillMatrixByUser(stMatrix& mx) {
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                std::string msg = "Enter value for [" + std::to_string(i + 1) + "][" + std::to_string(j + 1) + "]: ";
                mx.data[i][j] = inputvalidation::ReadPositiveNumber(msg);
            }
        }
    }

    void FillTransposeMatrix(const stMatrix& mx, stMatrix& result) { 

        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                result.data[j][i] = mx.data[i][j];
            }
        }
    }

    void FillMatrixWithOrderNumbers(stMatrix& mx) {
        int counter = 1;

        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                mx.data[i][j] = counter++;
            }
        }
    }
    
    void FillMatrixWithRandomNumbers(stMatrix& mx) {
        
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) 
            {
                mx.data[i][j] = myrandom::GetrandomNumberInRange(1, 100);
            }
        }
    } 
 
    void GetTranspose (const stMatrix& original, stMatrix& empty_matrix) 
    {   
        for (int i = 0; i < original.cols; i++)
        {
            for (int j = 0; j < original.rows; j++)
                empty_matrix.data[i][j] = original.data[j][i];
        }
    }    
    
    int GetMinNum(const stMatrix& original)
    {
        int minimum_value = original.data[0][0];

        for (int i = 0; i < original.rows; i++)
        {
            for (int j = 0; j < original.cols; j++)
            {
                if (original.data[i][j] < minimum_value)
                    minimum_value = original.data[i][j];
            }
        }
        return minimum_value;        
    }
    
    int GetMaxNum(const stMatrix& original)
    {
        int maximum_value = original.data[0][0];
        
        for (int i = 0; i < original.rows; i++)
        {
            for (int j = 0; j < original.cols; j++)
            {
                if (original.data[i][j] > maximum_value)
                    maximum_value = original.data[i][j];
            }
        }
        return maximum_value;        
    }
    
    //^ wrong for performance 

    // void FillIntersectedNums (const stMatrix& mx1, const stMatrix& mx2, int array[100])
    // {
    //     int counter = 0;

    //     for (int i = 0; i < mx1.rows; i++)
    //     {
    //         for (int j = 0; j < mx1.cols; j++)
    //         {
    //             if(IsNumberFound(mx2, mx1.data[i][j]))
    //             {
    //                 if(!array::IsNumberFoundInArray(array, counter, mx1.data[i][j]))
    //                 {
    //                     array[counter] = mx1.data[i][j];
    //                     counter++;
    //                 }
    //             }
    //         }
    //     }
    // }

    bool IsNumberFound(const stMatrix& mx, int number_to_find) {
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                if (mx.data[i][j] == number_to_find)
                    return true;
            }
        }
        return false;
    }

    bool IsSparceMatrix(const stMatrix& mx) {
        int total_elements = mx.rows * mx.cols;
        return CountNumberInMatrix(mx, 0) >= total_elements / 2;
    }

    bool IsIdentityMatrix(const stMatrix& mx) {
        if (mx.rows != mx.cols)
            return false;

        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                if ((i == j && mx.data[i][j] != 1) ||
                    (i != j && mx.data[i][j] != 0))
                    return false;
            }
        }
        return true;
    }

    bool IsScalarMatrix(const stMatrix& mx) {
        if (mx.rows != mx.cols)
            return false;

        int diagonal_value = mx.data[0][0];

        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                if ((i == j && mx.data[i][j] != diagonal_value) ||
                    (i != j && mx.data[i][j] != 0))
                    return false;
            }
        }
        return true;
    }

    
   
    
    void GetMiddleRow(const stMatrix& mx, int result_array[])
    {
        int mid = mx.rows / 2;
        for (int j = 0; j < mx.cols; j++) {
            result_array[j] = mx.data[mid][j];
        }
    }

    void Multiply(const stMatrix& mx1, const stMatrix& mx2, stMatrix& result) {
        for (int i = 0; i < mx1.rows; i++) {
            for (int j = 0; j < mx1.cols; j++) {
                result.data[i][j] = mx1.data[i][j] * mx2.data[i][j];
            }
        } 
    }

    
    void PrintMatrix(const stMatrix& mx) {
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                std::cout << std::setw(10) << mx.data[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    
    void SumMatrixRowsIntoArray(const stMatrix& mx, int result_array[])
    {
        for (int i = 0; i < mx.rows; i++) {
            result_array[i] = 0;
            for (int j = 0; j < mx.cols; j++) {
                result_array[i] += mx.data[i][j];
            }
        }
    }

    void SumMatrixColumnsIntoArray(const stMatrix& mx, int result_array[]) {
        for (int j = 0; j < mx.cols; j++) {
            result_array[j] = 0;
            for (int i = 0; i < mx.rows; i++) {
                result_array[j] += mx.data[i][j];
            }
        }
    }

    int SumOfMatrix(const stMatrix& mx) {
        int total = 0;
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                total += mx.data[i][j];
            }
        }
        return total;
    }

    
}
