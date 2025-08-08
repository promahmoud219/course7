// main.cpp


#include <iostream>

#include "matrix/matrix.hpp"
#include "mystring/mystring.hpp"
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
    mx2.rows = mx1.rows; 
    mx2.cols = mx1.cols;
    matrix::FillMatrixWithOrderNumbers(mx2);
    std::cout << "\nThe following is a " << mx2.rows << "x" << mx2.cols << " ordered matrix\"matrix2\":\n";
    matrix::PrintMatrix(mx2);

 
    matrix::stMatrix transpose_mx;
    transpose_mx.rows = mx1.rows;
    transpose_mx.cols = mx1.cols;
    matrix::GetTranspose(mx2, transpose_mx);
    std::cout << "\n\nthis is the transpose matrix of matrix2:\n";
    matrix::PrintMatrix(transpose_mx);
 

    matrix::stMatrix matrix_multiply;
    matrix_multiply.rows = mx1.rows;
    matrix_multiply.cols = mx1.cols;
    matrix::Multiply(mx1, mx2, matrix_multiply);
    std::cout << "\nthis is the result of  multiply matrix with matrix3:\n";
    matrix::PrintMatrix(matrix_multiply);

    std::cout << "\n\nthis is the middle row  of multiplied matrix\n";
    int middl_row_array[100];
    matrix::GetMiddleRow(matrix_multiply, middl_row_array);
    array::PrintArray(middl_row_array, mx1.cols);

    std::cout << "\nThis is the sum of matrix1: " << matrix::SumOfMatrix(mx1) << std::endl;

    matrix::stMatrix empty_matrix;
    empty_matrix.rows = mx1.rows;
    empty_matrix.cols = mx1.cols;
    matrix::CopyMatrix(matrix_multiply, empty_matrix);
    std::cout << "\n\nthis is empty matrix after being copied from multiplied matrix:\n";
    matrix::PrintMatrix(empty_matrix);
    

    if (matrix::AreMatricesEqual(matrix_multiply, empty_matrix))
        std::cout << "\nmatrix_multiply, empty_matrix are equals\n";
    else
        std::cout << "\nmatrix_multiply, empty_matrix are not equals\n";

        
    matrix::stMatrix matrix_by_user;
    matrix_by_user.rows = mx1.rows;
    matrix_by_user.cols = mx1.cols;
    matrix::FillMatrixByUser(matrix_by_user);
    if (matrix::IsIdentityMatrix(matrix_by_user))
        std::cout << "\nthis is an identity matrix\n";
    else    
        std::cout << "\nthis is not an identity matrix\n";    


    if (matrix::IsSparceMatrix(matrix_by_user))
        std::cout << "\nthis matrix \"matrix_by_user\" is sparce\n";
    else
        std::cout << "\nthis matrix \"matrix_by_user\" is not sparce\n";

    if (matrix::IsNumberFound(matrix_by_user, 10))
        std::cout << "\nnumber 10 is found in matrix_by_user: ";
    if (!matrix::IsNumberFound(matrix_by_user, 7))
        std::cout << "\nnumber 7 is notfound in matrix_by_user: ";


    std::cout << "\n\nthis is the min num in matrix_by_user:\n" << matrix::GetMinNum(matrix_by_user);
    std::cout << "\n\nthis is the max num in matrix_by_user:\n" << matrix::GetMaxNum(matrix_by_user) << std::endl;

    if (matrix::IsPalindromeMatrix(matrix_by_user))
        std::cout << "\n\nmatrix_by_user is a palindrome mx\n";
    else    
        std::cout << "\n\nmatrix_by_user is not a palindrome mx\n";


    
    std::string text = "mahmoud Ahmed abdel aal Ahmed";
    array::stArray first_letters;
    first_letters.length = 0;
    mystring::FillArrayWithFirstLetter(text, first_letters);
    std::cout << "\nFirst letters of this string: \n"; 
    array::PrintStringArray(first_letters, length);
    mystring::UpperFirstLetterOfEachWord(text);
    std::cout << "\nthis is the text after converting first letter of each word to upper case:\n" << text;
    
    mystring::LowerFirstLetterOfEachWord(text);
    std::cout << "\nthis is the text after converting first letter of each word to upper case:\n" << text;

    mystring::LowerAllString(text);
    std::cout << "\nconverting all string to lower:\n" << text;
    mystring::UpperAllString(text);
    std::cout << "\nconverting all string to upper:\n" << text;
    
    std::cout << "\nletter M to m:\n" << mystring::InvertLetterCase('M');
    std::cout << "\nletter m to M:\n" << mystring::InvertLetterCase('m') << std::endl;

    text = "MAHMOUD ahmed";
    std::cout << "\nInvert all string MAHMOUD ahmed:\n";
    mystring::InvertLetterCase(text);
    std::cout << text;

    std::cout << "\n\nsmall letters:\n" << mystring::CountSmallLetters(text);
    std::cout << "\n\ncapital letters:\n" << mystring::CountCapitalLetters(text);
    std::cout << "\n\nletters number:\n" << mystring::CountLetters(text);
    std::cout << "\nletter m was written " << mystring::CountLetter(text, 'm') << "times" << "\n";

    std::cout << "\na is vowel: " << mystring::IsVowel('a');
    std::cout << "\nNumber of vowels is:\n" << mystring::CountVowels(text);
    

    array::stArray st_array;
    st_array.data[100];
    st_array.length = 0;
    mystring::GetVowels(text, st_array);
    std::cout << "\nthese are the vowels of Mahmoud Ahmed Abdel Ahmed:\n";
    array::PrintStringArray()



}
