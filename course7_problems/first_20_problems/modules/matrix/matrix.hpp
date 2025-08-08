// matrix.hpp

#pragma once

#include <iostream>


namespace matrix {
    
    struct stMatrix {
        int data[100][100];
        int rows;
        int cols;
    };

    
    // //& this is a helper
    // stMatrix CreateMatrix(int rows, int cols) {
    //     stMatrix mx;
    //     mx.rows = rows;
    //     mx.cols = cols;
    //     return mx;
    // }

    
    bool AreMatricesEqual(const stMatrix& a, const stMatrix& b);
    
    void CopyMatrix(const stMatrix& original, stMatrix& empty_mx);
    int CountNumberInMatrix(const stMatrix& mx, int number_to_count);
    
    void FillMatrixByUser(stMatrix& mx);
    void FillMatrixWithRandomNumbers(stMatrix& mx);
    void FillMatrixWithOrderNumbers(stMatrix& mx);
    
    void GetTranspose(const stMatrix& original, stMatrix& transposed_matrix);
    void GetMiddleRow(const stMatrix& mx, int result_array[]);
    int GetMinNum(const stMatrix& original);
    int GetMaxNum(const stMatrix& original);
    
    bool IsScalarMatrix(const stMatrix& mx);
    bool IsIdentityMatrix(const stMatrix& mx);
    bool IsNumberFound(const stMatrix& mx, int number_to_find);
    bool IsSparceMatrix(const stMatrix& mx);
    
    void Multiply(const stMatrix& mx1, const stMatrix& mx2, stMatrix& result);;
    
    void PrintMatrix(const stMatrix& mx);
    
    int SumOfMatrix(const stMatrix& mx);
    void SumMatrixRowsIntoArray(const stMatrix& mx, int result_array[]);
    void SumMatrixColumnsIntoArray(const stMatrix& mx, int result_array[]);
    

}
