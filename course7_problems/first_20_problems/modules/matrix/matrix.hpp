// matrix.hpp

namespace matrix {

    void FillMatrixWithRandomNumbers (int matrix_array[100][100], int row, int column);
    void FillMatrixWithOrderNumbers (int matrix_array[100][100], int row, int column); 
    void PrintMatrix (int matrix_array[100][100], int row, int column); 
    void SumMatrixRowsIntoArray (int matrix[100][100], int result_array[], int row, int column);
    void SumMatrixColumnsIntoArray (int matrix[100][100], int result_array[], int row, int column);
    void FillTransposeMatrix (int matrix[100][100], int transpose_matrix[100][100], int row, int column);

}