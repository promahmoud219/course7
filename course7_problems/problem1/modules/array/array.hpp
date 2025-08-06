// array.hpp

#pragma once

namespace array {
    void SumOfTwoArrays (int array_to_be_filled[], int array1[], int array2[], int arr_length);
    bool IsNumberFoundInArray (const int arr[], int arr_length, int number_to_check);
    int PrimeNumbersInArray (const int arr[], int arr2[], int arr_length);
    void PrintArray(const int arr[], int length);
    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength);
    void ReadArray (int arr[], int arr_length);
    int CountElementRepetation(int arr[], int arr_length, int value);
    void FillArrayWithRandomElements (int arr[], int arr_length, int random_from, int random_to);
    int GetMaximumValue (int arr[], int arr_length);
    int GetMinimumValue (int arr[], int arr_length);
    int GetSumArray (int arr[], int arr_length);
    float GetAverageArray (int arr[], int arr_length);
    void ShuffleArray (int arr[], int array_length);
    void FillArrayWithReversedOrder (int arr_source[], int arr_destination[], int array_length);
    void FillArrayWithRandomKeys (std::string arr[], int array_length);
    void PrintStringArray(const std::string arr[], int length);
    int FindNumberInArry (int array[], int array_length, int check_number);
    bool IsNumberFoundInArray (int array[], int array_length, int check_number);
    void FillPositiveArrayByUser (int array[], int& array_length);
    void FillArrayByUser (int array[], int& array_length);
    void AddArrayElement(int array[100], int &array_length, int number);
    void CopyArrayUsingAddArrayElement (int array_source[100], int array_destination[100], int source_length, int& destination_length);
    void CopyOddNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length);
    void CopyPrimeNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length);
    void CopyDistinctNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length);
    bool IsPalindromeArray (int array[], int array_length);
    int OddNumbersCount (int array[], int array_length);
    int EvenNumbersCount (int array[], int array_length);
    int PositiveNumbersCount (int array[], int array_length);
    int NegativeNumbersCount (int array[], int array_length);
    void PrintRowsSumArray(const int array[], int length);
        
}


