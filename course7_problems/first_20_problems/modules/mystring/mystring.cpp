// mystring.cpp


#include <iostream>
#include <string>

#include "mystring.hpp"
#include "array/array.hpp"
namespace mystring {

    void SplitString (std::string& text, array::stArray& array)
    {
        array.length = 0;
        std::string delim = " "; 
        short pos = 0; 
        std::string sWord; // define a string variable  // use find() function to get the position of the delimiters  
        while ((pos = text.find(delim)) != std::string::npos)     
        {         
            sWord =text.substr(0, pos); // store the word   
            if (sWord !="")         
            {
                array.data[array.length] = sWord;
                array.length++;
            }
            text.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */    
        } 
        if (text!="")     
        {
            array.data[array.length] = sWord;
            array.length++;
        }

            
 
    }

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

    int CountCapitalLetters(const std::string& text) 
    {
        int Counter = 0; 
        for (char c : text)
        { 
            if (isupper(c))
                Counter++;     
        } 
        return Counter; 
    } 
    
    int CountSmallLetters(const std::string& text) 
    { 
        int Counter = 0; 

        for (char c : text)     
        { 
            if (islower(c))             
                Counter++;     
        } 

        return Counter; 
    }
    
    void FillArrayWithFirstLetter (const std::string& text, array::stArray array)
    {
        bool isFirstLetter = true;    
        array.length = 0;

        for (char c : text)
        {
            if (c != ' ' && isFirstLetter)
            {             
                array.data[array.length] = c;
                array.length++;
            }         
            isFirstLetter = (c == ' ' ? true : false);
        }
        
    }
    
    
    void PrintEachWordInString(std::string text) 
    { 
        std::string delim = " "; // delimiter      
        std::cout <<"\nYour string wrords are: \n\n"; short pos = 0; std::string sWord; // define a string variable  // use find() function to get the position of the delimiters  
        while ((pos = text.find(delim)) != std::string::npos)     
        {         
            sWord =text.substr(0, pos); // store the word   
            if (sWord !="")         
            {             
                std::cout << sWord << std::endl;         
            } 
            text.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */    
        
        } 
        if (text!="")     
        {         
            std::cout <<text<< std::endl; // it print last word of the string.    
        } 

    }

    int CountEachWordInString(std::string& text) 
    { 
        int counter = 0;
        std::string delim = " "; // delimiter      
        // std::cout <<"\nYour string wrords are: \n\n";
        short pos = 0; 
        std::string sWord; // define a string variable  // use find() function to get the position of the delimiters  
        while ((pos = text.find(delim)) != std::string::npos)     
        {         
            sWord =text.substr(0, pos); // store the word   
            if (sWord !="")         
                counter++;       
            text.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */    
        } 
        if (text!="")     
            counter++; // it print last word of the string.    

        return counter;
    }
    
    void GetVowels (const std::string& text, array::stArray& array)
    {
        array.length = 0;

        for (char c : text)
        {
            if (IsVowel(c))
            {
                array.data[array.length] = c;
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