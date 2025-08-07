// inputvalidation.hpp

#include <iostream>
#include <string> 
#include <limits> 

#include "inputvalidation.hpp" 

namespace inputvalidation {

    int ReadPositiveNumber(const std::string& prompt) {
        
        int number;

        while (true) {
            std::cout << prompt;
            std::cin >> number;

            if (std::cin.fail() || number < 0) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter a positive number.\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extra input
                return number;
            }
        }
    }



    std::string ReadString(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ✅ flush newline from previous input
        std::getline(std::cin, input);
        return input;
    }

    char ReadYesNo (const std::string& message) {
        return 'y';
    }
    
    int ReadNumberInRange (std::string message, int min, int max) {

        int number = 0;

        do
        {
            std::cout << message;
            std::cin >> number;

        } while (number < min || number > max);
        
        return number;
    }

    int ReadNumber (std::string message) {

        int number = 0;
        
        std::cout << message;
        std::cin >> number;

        return number;
    }
} 
