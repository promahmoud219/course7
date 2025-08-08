// array.cpp

#include <iostream>
#include <string>
#include <iomanip>

#include "array.hpp"
#include "../inputvalidation/inputvalidation.hpp"
#include "../primenumbers/primenumbers.hpp"
#include "../myrandom/random.hpp"
#include "../generateKeys/generateKeys.hpp"

namespace array {

    
    bool IsNumberFoundInArray (int array[], int array_length, int check_number) 
    {
        return FindNumberInArry(array, array_length, check_number) != -1;
    }
    
    void SumOfTwoArrays (int array_to_be_filled[], int array1[], int array2[], int array_length) 
    {
        for (int i = 0; i < array_length; i++)
        {
            array_to_be_filled[i] = array1[i] + array2[i];
        }
        
    }

    bool IsNumberFoundInArray (const int array[], int array_length, int number_to_check) 
    {
        for (int i = 0; i < array_length; i++)
        {
            if (number_to_check == array[i])
                return true;
        }
        return false;
    }

    int PrimeNumbersInArray (const int array[], int arr2[], int array_length) 
    {
        int count = 0;

        for (int i = 0; i < array_length; i++)
        {
            if (primenumbers::IsPrime(array[i]))
            {
                if (!IsNumberFoundInArray(arr2, count, array[i])) 
                {
                    arr2[count] = array[i];
                    count++;
                }
            }
        }
        return count;
    }
    
    void PrintArray(const int array[], int length) {

        
        for (int i = 0; i < length; ++i) 
        {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";

    }

    void PrintStringArray(const stArray array) {
        
        for (int i = 0; i < array.length; ++i) 
        {
            std::cout << array.data[i] << " ";
        }
        std::cout << "\n";
    }

    void PrintRowsSumArray(const int array[], int length) {
        
        
        for (int i = 0; i < length; ++i) 
        {
            std::cout << std::setw(5) << std::left << "Row " << i + 1 << " Sum = " << array[i] << std::endl;
        }
        std::cout << "\n";

    }
    

    void PrintColumnsSumArray(const int array[], int length) {
        
        std::cout << "\n";

        for (int i = 0; i < length; ++i) 
            std::cout << std::setw(7) << std::left << "Column " << i + 1 << " Sum = " << array[i] << "\n";

        std::cout << std::endl;

    }
    
 

    void AddArrayElement(int array[100], int &array_length, int number)
    {
        array_length++;
        array[array_length - 1] = number;
    }

    void CopyArray(int source_array[100], int destination_array[100], int array_length)
    {
    // Loop through each element up to array_length and copy from source to destination.
        for (int i = 0; i < array_length; i++)
            destination_array[i] = source_array[i];
    }
    
    void CopyArrayUsingAddArrayElement (int source_array[100], int destination_array[100], int source_length,  int& destination_length)
    {
        for (int i = 0; i < source_length; i++)
        {
            AddArrayElement(destination_array, destination_length, source_array[i]);
        }
    }
    
    void CopyOddNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length) 
    {
        for (int i = 0; i < source_length; i++)
        {
            if (source_array[i] % 2 != 0)
                AddArrayElement(destination_array, destination_length, source_array[i]);
        }

    }

    void CopyPrimeNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length) 
    {
        for (int i = 0; i < source_length; i++)
        {
            if (primenumbers::IsPrime(source_array[i]))
                AddArrayElement(destination_array, destination_length, source_array[i]);
        }

    }
    
    void CopyDistinctNumbersFromArray (int source_array[100], int destination_array[100], int source_length,  int& destination_length) 
    {
        for (int i = 0; i < source_length; i++)
        {
            if (!IsNumberFoundInArray(destination_array, destination_length, source_array[i]))
                AddArrayElement(destination_array, destination_length, source_array[i]);
        }

    }

    void ReadArray (int array[], int array_length) {
        // int array_length = inputvalidation::ReadPositiveNumber("Enter array array_length (max " + std::to_string(array_length) + "): ");
        array_length = std::min(array_length, array_length); // Prevent overflow

        std::cout << "Enter " << array_length << " element(s): \n";
        for (int i = 0; i < array_length; ++i) {
            std::cin >> array[i];
            std::cout << std::endl;
        }
 
    }

    int CountElementRepetation(int array[], int array_length, int value) {
        if (array_length == 0) return 0;

        int count = 0;

        for (int i = 0; i < array_length; ++i) {
            if (array[i] == value) {
                count++;
            }
        }

        return count;
    }

    void FillArrayWithRandomElements (int array[], int array_length, int random_from, int random_to) {
        
        for (int i = 0; i < array_length; i++) 
        {
            array[i] = myrandom::GetrandomNumberInRange(random_from, random_to);
        }
    }

    int GetMaximumValue (int array[], int array_length) 
    {
        int maximum_value = 0;

        for (int i = 0; i < array_length; i++)
        {
            if (array[i] > maximum_value)
            {
                maximum_value = array[i];
            }
                
        }
        return maximum_value;
    }
    
    int GetMinimumValue (int array[], int array_length) 
    {
        int minimum_value = array[0];

        for (int i = 0; i < array_length; i++)
        {
            if (array[i] < minimum_value)
            {
                minimum_value = array[i];
            }
                
        }
        return minimum_value;
    }
    
    int GetSumArray (int array[], int array_length) 
    {
        int sum = 0;

        for (int i = 0; i < array_length; i++)
        {
           sum += array[i];
        }

        return sum;
    }

    float GetAverageArray (int array[], int array_length) 
    {
        return (float)GetSumArray(array, array_length) / array_length;
    }

    void ShuffleArray (int array[], int array_length) {

        int j = 0;

        for (short i = array_length - 1; i > 0; i--)
        {
            j = myrandom::GetrandomNumberInRange(0, i);
            std::swap(array[i], array[j]);
        }
        
    }

    void FillArrayWithReversedOrder (int arr_source[], int arr_destination[], int array_length) 
    {
        for (int i = 0; i < array_length; i++)
            arr_destination[i] = arr_source[array_length - 1 - i ];
    }

    void FillArrayWithRandomKeys (std::string array[], int array_length) 
    {
        for (int i = 0;i < array_length; i++)
        {
            array[i] = generateKeys::GenerateKeys(4);
        }
    }

    int FindNumberInArry (int array[], int array_length, int check_number) 
    {
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] == check_number)
                return i;
        }
        return -1;
    }

    void FillPositiveArrayByUser (int array[], int& array_length) 
    {
        bool addMore = true;
        int number = 0;
        do
        {
            number = inputvalidation::ReadPositiveNumber("\nPlease enter a number:\n");
            AddArrayElement(array, array_length, number);

            addMore = inputvalidation::ReadNumberInRange("\nDo you want to add more numbers? [0]: No, [1]: Yes?\n", 0, 1);
            std::cin.get();
            
        } while (addMore);
    }

    void FillArrayByUser (int array[], int& array_length) 
    {
        bool addMore = true;
        int number = 0;
        do
        {
            number = inputvalidation::ReadNumber("\nPlease enter a number:\n");
            AddArrayElement(array, array_length, number);

            addMore = inputvalidation::ReadNumberInRange("\nDo you want to add more numbers? [0]: No, [1]: Yes?\n", 0, 1);
            std::cin.get();
            
        } while (addMore);
    }

    bool IsPalindromeArray (int array[], int array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] != array[array_length - i - 1])
                return false;
        }
        return true;
    }

    int OddNumbersCount (int array[], int array_length)
    {
        int count = 0;

        for (int i = 0; i < array_length; i++)
        {
            if (array[i] % 2 != 0)
                count++;
        }
        return count;
    }
    
    int EvenNumbersCount (int array[], int array_length)
    {
        int count = 0;
    
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] % 2 == 0)
                count++;
        }
        return count;
    }

    int PositiveNumbersCount (int array[], int array_length)
    {
        int count = 0;
    
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] >= 0)
                count++;
        }
        return count;
    }

    int NegativeNumbersCount (int array[], int array_length)
    {
        int count = 0;
    
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] < 0)
                count++;
        }
        return count;
    }

    
}
