// primenumbers.cpp

#include <vector> 

#include "primenumbers.hpp"

namespace primenumbers {

    bool IsPrime (int number) {
    
        if (number < 2)
            return false;

        for (int counter = 2; counter * counter <= number; counter++) {
            
            if ( number % counter == 0)
                return false;
            
        }
        return true;
    } 

    std::vector<int> GetvprimenumbersInRange (int num1, int num2) {
    
        int temp = 0;
        
        if (num1 > num2) {
            temp = num2;
            num2 = num1;
            num1 = temp;
        }
    
        std::vector<int> vprimenumbers;
        
        for (int i = num1; i <= num2; i++) {
    
            if (IsPrime (i) == true)
                vprimenumbers.push_back(i);
        }
        return vprimenumbers;
    }
    

}