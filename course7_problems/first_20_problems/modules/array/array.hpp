// array.hpp

#pragma once

namespace array {

    struct stArray {
        std::string data[100];
        int length = 0;
    };

    void AddArrayElement(int array[100], int &array_length, int number);
    
    void CopyArrayUsingAddArrayElement (int array_source[100], int array_destination[100], int source_length, int& destination_length);
    void CopyOddNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length);
    void CopyPrimeNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length);
    void CopyDistinctNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length);
    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength);
    int CountElementRepetation(int arr[], int arr_length, int value);
    
    int EvenNumbersCount (int array[], int array_length);
    
    int FindNumberInArry (int array[], int array_length, int check_number);
    void FillArrayWithRandomElements (int arr[], int arr_length, int random_from, int random_to);
    void FillPositiveArrayByUser (int array[], int& array_length);
    void FillArrayByUser (int array[], int& array_length);
    void FillArrayWithReversedOrder (int arr_source[], int arr_destination[], int array_length);
    void FillArrayWithRandomKeys (std::string arr[], int array_length);
    
    int GetMaximumValue (int arr[], int arr_length);
    int GetMinimumValue (int arr[], int arr_length);
    int GetSumArray (int arr[], int arr_length);
    float GetAverageArray (int arr[], int arr_length);
    
    
    bool IsNumberFoundInArray (const int arr[], int arr_length, int number_to_check);
    bool IsNumberFoundInArray (int array[], int array_length, int check_number);
    bool IsPalindromeArray (int array[], int array_length);
    
    int NegativeNumbersCount (int array[], int array_length);
    
    int OddNumbersCount (int array[], int array_length);
    
    void PrintStringArray(const stArray array);
    void PrintArray(const int arr[], int length);
    int PositiveNumbersCount (int array[], int array_length);
    int PrimeNumbersInArray (const int arr[], int arr2[], int arr_length);
    void PrintRowsSumArray(const int array[], int length);
    void PrintColumnsSumArray(const int array[], int length);
    
    void ReadArray (int arr[], int arr_length);
    
    void ShuffleArray (int arr[], int array_length);
    void SumOfTwoArrays (int array_to_be_filled[], int array1[], int array2[], int arr_length);
        
}


