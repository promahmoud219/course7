// mystring.hpp

#pragma once

#include <string>

namespace mystring {
    
    std::string  ReadString();
    void FillArrayWithFirstLetter (const std::string& text, std::string array[100], int& length);
    
}