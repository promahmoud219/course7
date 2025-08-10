// mystring.cpp


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "mystring.hpp"
#include "../array/array.hpp"
namespace mystring {

    std::string ReverseStringCopy(const std::string& text, const std::string& delimiter)
    {
        std::string result = text;
        ReverseString(result, delimiter);
        return result;
    }

    void ReverseString(std::string& text, const std::string& delimiter)
    {
        if (text.empty())
            return;

        // Split into words
        std::vector<std::string> words;
        size_t start = 0, pos;
        while ((pos = text.find(delimiter, start)) != std::string::npos) {
            std::string word = text.substr(start, pos - start);
            if (!word.empty())
                words.push_back(word);
            start = pos + delimiter.size();
        }

        // Add last word if exists
        if (start < text.size())
            words.push_back(text.substr(start));

        // Reverse the vector
        std::reverse(words.begin(), words.end());

        // Join back into a single string
        text = JoinString(words, delimiter);
    }


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
    
    void FillArrayWithFirstLetter (const std::string& text, array::stArray& array)
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


    std::string JoinString (const std::vector<std::string>& vector_string, const std::string& delimeter)
    {
        if (vector_string.empty())
            return "";

        size_t total_length = 0;        
        for (const std::string& word : vector_string)
                total_length += word.size();
        
        std::string connected_string;

        connected_string.reserve(total_length);

        for (const std::string& word: vector_string)
        {
            connected_string += word;
            connected_string += delimeter; 
        }

        TrimRight(connected_string);
        return connected_string;
    }

    std::string JoinString(const array::stArray& arr, const std::string& delimiter) {
       
        if (arr.length == 0)
            return "";

        size_t total_length = 0;
        for (size_t i = 0; i < arr.length; ++i)
            total_length += arr.data[i].size() + delimiter.size();

        std::string connected_string;
        connected_string.reserve(total_length);

        for (size_t i = 0; i < arr.length; ++i) {
            connected_string += arr.data[i];
            if (i != arr.length - 1)
                connected_string += delimiter;
        }

        return connected_string;
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
    
    
    std::string TrimCopy(const std::string& text) {
        if (text.empty())
            return "";

        std::string result = text;
        TrimLeft(result);
        TrimRight(result);
        return result;
    }
    
    void Trim(std::string& text) {
        TrimLeft(text);
        TrimRight(text);
    }
    void TrimLeft(std::string& text) {
        if (text.empty())
            return;

        for (size_t i = 0; i < text.length(); ++i) {
            if (text[i] != ' ') {
                text.erase(0, i); // remove leading spaces
                return;
            }
        }
        text.clear(); // all spaces
    }

    void TrimRight(std::string& text) {
        if (text.empty())
            return;

        for (size_t i = text.length(); i > 0; --i) {
            if (text[i - 1] != ' ') {
                text.erase(i); // remove trailing spaces
                return;
            }
        }
        text.clear(); // all spaces
    }

    std::string TrimLeftCopy(const std::string& text) {
        if (text.empty())
            return "";

        std::string result = text;
        TrimLeft(result); // reuse in-place
        return result;
    }

    std::string TrimRightCopy(const std::string& text) {
        if (text.empty())
            return "";

        std::string result = text;
        TrimRight(result); // reuse in-place
        return result;
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