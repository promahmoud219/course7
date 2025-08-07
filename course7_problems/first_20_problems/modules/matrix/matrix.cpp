// matrix.cpp

#include <iostream>
#include <iomanip>

#include "matrix.hpp"
#include "../myrandom/random.hpp"
#include "../inputvalidation/inputvalidation.hpp"

namespace matrix {

    bool AreMatricesEqual(const stMatrix& m1, const stMatrix& m2) {
        if (m1.rows != m2.rows || m1.cols != m2.cols)
            return false;

        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.cols; j++) {
                if (m1.data[i][j] != m2.data[i][j])
                    return false;
            }
        }
        return true;
    }

    matrix::stMatrix CopyMatrix (const stMatrix& source) 
    {
        matrix::stMatrix empty_mx;
        
        empty_mx.rows = source.rows;
        empty_mx.cols = source.cols;

        for (int i = 0; i < source.rows; i++) {
            for (int j = 0; j < source.cols; j++) 
                empty_mx.data[i][j] = source.data[i][j];
        }
        return empty_mx;
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
        result.rows = mx.cols;
        result.cols = mx.rows;
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

    
   
    void MiddleRow(const stMatrix& mx, int array[100]) {
        int mid = mx.rows / 2;
        for (int j = 0; j < mx.cols; j++) {
            array[j] = mx.data[mid][j];
        }
    }
    void GetMiddleRow(const stMatrix& m, int result_array[])
    {
        
    }

    void MultiplyTwoMatrices(const stMatrix& m1, const stMatrix& m2, stMatrix& result) {
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.cols; j++) {
                result.data[i][j] = m1.data[i][j] * m2.data[i][j];
            }
        }
        result.rows = m1.rows;
        result.cols = m1.cols;
    }

    
    void PrintMatrix(const stMatrix& mx) {
        for (int i = 0; i < mx.rows; i++) {
            for (int j = 0; j < mx.cols; j++) {
                std::cout << std::setw(10) << mx.data[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    
    void SumMatrixRowsIntoArray(const stMatrix& mx, int result[100]) {
        for (int i = 0; i < mx.rows; i++) {
            result[i] = 0;
            for (int j = 0; j < mx.cols; j++) {
                result[i] += mx.data[i][j];
            }
        }
    }

    void SumMatrixColumnsIntoArray(const stMatrix& mx, int result[100]) {
        for (int j = 0; j < mx.cols; j++) {
            result[j] = 0;
            for (int i = 0; i < mx.rows; i++) {
                result[j] += mx.data[i][j];
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
