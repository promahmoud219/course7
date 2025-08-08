// mystring.hpp

#pragma once

#include <string>

namespace mystring {
    
    void InvertLetterCase (std::string& text);
    char InvertLetterCase (char c);
    std::string  ReadString();
    void FillArrayWithFirstLetter (const std::string& text, std::string array[100], int& length);
    void UpperFirstLetterOfEachWord (std::string& text);
    void LowerFirstLetterOfEachWord (std::string& text);
    void LowerAllString (std::string& text);
    void UpperAllString (std::string& text);
    
}