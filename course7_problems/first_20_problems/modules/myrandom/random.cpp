// random.cpp

#include <iostream>
#include <random>

#include "random.hpp"





namespace myrandom {

    
    int GetrandomNumberInRange (int min, int max) {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
    
    char RandomCharacter (enRandomCharacter random_char) {

        switch (random_char)
        {
            case enRandomCharacter::lowerCaseLetter:
                return static_cast<char>(GetrandomNumberInRange(97, 122));
            case enRandomCharacter::upperCaseLetter:
                return static_cast<char>(GetrandomNumberInRange(65, 90));
                case enRandomCharacter::specialCharacter:
                return static_cast<char>(GetrandomNumberInRange(33, 47));
            case enRandomCharacter::digit:
                return static_cast<char>(GetrandomNumberInRange(48, 57));
            default:
                //~ use cerr instead of cout for errors.
                std::cerr << "there is problem in randomCharacter In random.cpp file \n";
                //! default return is 0
                return '0';
                break;
        }
             
    }
        
}
