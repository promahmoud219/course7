// mystring.cpp


#include <iostream>
#include <string>

namespace mystring {

    std::string  ReadString() { 
        std::string text;     
        std::cout << "Please Enter Your String?\n";     
        std::getline(std::cin, text); return text; 
    } 

    void FillArrayWithFirstLetter (const std::string& text, std::string array[100], int& length)
    {
        bool isFirstLetter = true;    

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



}