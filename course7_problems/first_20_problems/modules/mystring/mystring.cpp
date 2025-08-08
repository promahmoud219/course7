// mystring.cpp


#include <iostream>
#include <string>

namespace mystring {


    char InvertLetterCase (char c)
    {
        return islower(c)? toupper(c) : tolower(c);
    }

    void InvertLetterCase (std::string& text)
    {
        for (char& c : text) 
            c = InvertLetterCase(c);
    }
    
    std::string  ReadString() { 
        std::string text;     
        std::cout << "Please Enter Your String?\n";     
        std::getline(std::cin, text); return text; 
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
    
    void LowerAllString (std::string& text)
    {
        for (int i = 0; i < text.length(); i++)
            text[i] = tolower(text[i]);
    }

    void UpperAllString (std::string& text)
    {
        for (int i = 0; i < text.length(); i++)
            text[i] = toupper(text[i]);
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