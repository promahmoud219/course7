// matrix.hpp

#pragma once

#include <iostream>


namespace matrix {
    
    struct stMatrix {
        int data[100][100];
        int rows;
        int cols;
    };
    
    
    
    bool AreMatricesEqual(const stMatrix& a, const stMatrix& b);
    
    matrix::stMatrix CopyMatrix(const stMatrix& original);
    int CountNumberInMatrix(const stMatrix& m, int number_to_count);
    
    void FillMatrixByUser(stMatrix& m);
    void FillMatrixWithRandomNumbers(stMatrix& m);
    void FillMatrixWithOrderNumbers(stMatrix& m);
    
    stMatrix GetTranspose(const stMatrix& original);
    void GetMiddleRow(const stMatrix& m, int result_array[]);
    
    bool IsScalarMatrix(const stMatrix& m);
    bool IsIdentityMatrix(const stMatrix& m);
    bool IsNumberFound(const stMatrix& m, int number_to_find);
    bool IsSparceMatrix(const stMatrix& m);
    
    Matrix Multiply(const stMatrix& a, const stMatrix& b);
    
    void PrintMatrix(const stMatrix& m);
    
    int SumOfMatrix(const stMatrix& m);
    void SumMatrixRowsIntoArray(const stMatrix& m, int result_array[]);
    void SumMatrixColumnsIntoArray(const stMatrix& m, int result_array[]);
    

}
