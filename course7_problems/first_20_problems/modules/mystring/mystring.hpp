// mystring.hpp

#pragma once

#include <string>

namespace mystring {
    
    enum enWhatToCount {smallLetters=0, capitalLetters=1, all=3};
    int CountLetter (const std::string& text, char letter, bool matchCase=true);
    int CountLetters (const std::string& text, enWhatToCount whatToCount=enWhatToCount::all);
    int  CountCapitalLetters(const std::string& S1);
    int  CountSmallLetters(const std::string& S1);
    int CountVowels (const std::string& text);
    void GetVowels (const std::string& text, array::stArray array);
    void InvertLetterCase (std::string& text);
    char InvertLetterCase (char c);
    bool IsVowel(char c);
    std::string  ReadString();
    void FillArrayWithFirstLetter (const std::string& text, std::string array[100], int& length);
    void UpperFirstLetterOfEachWord (std::string& text);
    void LowerFirstLetterOfEachWord (std::string& text);
    void LowerAllString (std::string& text);
    void UpperAllString (std::string& text);
    
}