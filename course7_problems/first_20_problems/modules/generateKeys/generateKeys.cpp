// generateKeys.cpp

#include <string>

#include "generateKeys/generateKeys.hpp"
#include "../myrandom/random.hpp"

namespace generateKeys {

    std::string GeneratRandomWord() {

        std::string word = "";
        
        word += myrandom::RandomCharacter(myrandom::enRandomCharacter::digit);
        word += myrandom::RandomCharacter(myrandom::enRandomCharacter::lowerCaseLetter);
        word += myrandom::RandomCharacter(myrandom::enRandomCharacter::upperCaseLetter);
        word += myrandom::RandomCharacter(myrandom::enRandomCharacter::specialCharacter);

        return word;
    }
    
    std::string GenerateKeys (int numberOfKeys) {
        
        std::string key = "";
        for (int i = 0; i < numberOfKeys; i++)
        {
            key += GeneratRandomWord();
        }
        return key;

    }



}