// random.hpp

#pragma once 
 

namespace myrandom {
    
    enum enRandomCharacter {lowerCaseLetter=1, upperCaseLetter=2, specialCharacter=3, digit=4};     
        
    char RandomCharacter (enRandomCharacter random_char);
    int GetrandomNumberInRange (int min, int max);
    
}