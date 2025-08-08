// mystring.cpp


#include <iostream>
#include <string>

#include "mystring.hpp"
#include "array/array.hpp"
namespace mystring {

    

    int CountVowels (const std::string& text)
    {
        int counter = 0;

        for ( char c : text)
        {
            if (IsVowel(c))
                counter++;
        }
        
        return counter;
    }

    int CountLetter(const std::string& text, char letter, bool matchCase)
    {
        int counter = 0;

        for (char c : text)
        {
            if (matchCase) {
                if (c == letter) counter++;
            }
            else {
                if (
                    std::tolower(static_cast<unsigned char>(c)) ==
                    std::tolower(static_cast<unsigned char>(letter))){
                    counter++;
                }
            }
        }
        return counter;
    }

    int CountLetters (const std::string& text, enWhatToCount whatToCount)
    {
        if (whatToCount = enWhatToCount::all)
            return text.length();

        int counter = 0;

        for (char c : text)
        {
            if (whatToCount==enWhatToCount::capitalLetters && isupper(c))
                counter++;

            if (whatToCount == enWhatToCount::smallLetters && islower(c))
                counter++;
        }

        return counter;
    }

    int CountCapitalLetters(const std::string& S1) 
    {
        int Counter = 0; 
        for (char c : S1)
        { 
            if (isupper(c))
                Counter++;     
        } 
        return Counter; 
    } 
    
    int CountSmallLetters(const std::string& S1) 
    { 
        int Counter = 0; 

        for (char c : S1)     
        { 
            if (islower(c))             
                Counter++;     
        } 

        return Counter; 
    }
    
    void FillArrayWithFirstLetter (const std::string& text, std::string array[100], int& length)
    {
        bool isFirstLetter = true;    
        length = 0;

        for (int i = 0; i < text.length(); i++)
        {

            if (text[i] != ' ' && isFirstLetter)
            {             
                array[length] = text[i];
                length++;
            }         
            isFirstLetter = (text[i] == ' ' ? true : false);
        }
        
    }
    
    void GetVowels (const std::string& text, array::stArray array)
    {
        array.length = 0;

        for (char c : text)
        {
            if (IsVowel(c))
            {
                array[array.length] = c;
                array.length++;
            }
        }
    }

    char InvertLetterCase (char c)
    {
        return islower(c)? toupper(c) : tolower(c);
    }

    void InvertLetterCase (std::string& text)
    {
        for (char& c : text) 
            c = InvertLetterCase(c);
    }
    
    bool IsVowel(char c)
    {
        static const std::string vowels = "aeiou"; // created once
        c = std::tolower(static_cast<unsigned char>(c));
        return vowels.find(c) != std::string::npos;
    }

    void LowerAllString (std::string& text)
    {
        for (int i = 0; i < text.length(); i++)
            text[i] = tolower(text[i]);
    }
    
    void LowerFirstLetterOfEachWord (std::string& text)
    {
        bool isFirstLetter = true;    
    
        for (int i = 0; i < text.length(); i++)
        {
    
            if (text[i] != ' ' && isFirstLetter)
            {             
                text[i] = tolower(text[i]);
            }         

            isFirstLetter = (text[i] == ' ' ? true : false);
        }

    }

    
    std::string  ReadString() { 
        std::string text;     
        std::cout << "Please Enter Your String?\n";     
        std::getline(std::cin, text); return text; 
    } 
     
    
    void UpperAllString (std::string& text)
    {
        for (int i = 0; i < text.length(); i++)
            text[i] = toupper(text[i]);
    }

    void UpperFirstLetterOfEachWord (std::string& text)
    {
        bool isFirstLetter = true;    
    
        for (int i = 0; i < text.length(); i++)
        {
    
            if (text[i] != ' ' && isFirstLetter)
            {             
                text[i] = toupper(text[i]);
            }         

            isFirstLetter = (text[i] == ' ' ? true : false);
        }

    }


}