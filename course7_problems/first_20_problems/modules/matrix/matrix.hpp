// matrix.hpp

namespace matrix {

    void FillMatrixWithRandomNumbers (int matrix_array[100][100], int row, int column);
    void FillMatrixWithOrderNumbers (int matrix_array[100][100], int row, int column); 
    void PrintMatrix (int matrix_array[100][100], int row, int column); 
    void SumMatrixRowsIntoArray (int matrix[100][100], int result_array[], int row, int column);
    void SumMatrixColumnsIntoArray (int matrix[100][100], int result_array[], int row, int column);
    void FillTransposeMatrix (int matrix[100][100], int transpose_matrix[100][100], int row, int column);
    void MultiplyTwoMatrices (int matrix1[100][100], int matrix2[100][100], int  empty_matrix[100][100], int row, int column);
    void MiddleRow (int matrix[100][100], int array[100], int row, int column);
    int SumOfMatrix (int matrix[100][100], int row, int column);
    bool AreMatricesEqual (int matrix1[100][100], int matrix2[100][100], int row, int column);
    void CopyMatrix (int matrix[100][100], int empty_matrix[100][100], int row, int column);

}