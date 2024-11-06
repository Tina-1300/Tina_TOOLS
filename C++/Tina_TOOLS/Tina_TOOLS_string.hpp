#pragma once


#include <iostream>
#include <string>
#include <algorithm> // reverse
#include <bitset> // pour le binaire ce renseigner sur la doc 

 

// condition ? expressionSiVrai : expressionSiFaux;
namespace Tina{


    class Tina_TOOLS_string{
    public:
        static std::string Tina_reverseString(std::string str){
            std::reverse(str.begin(), str.end());
            return str;
        }
        
        static int Tina_Compare(std::string str, const char *str_a_comparer){
            if(str.compare(str_a_comparer) == 0){
                return true;
            }else{
                return false;
            }
        }

        static std::string Tina_convert_string_to_binary(std::string str){
            std::string  binaryString;
            for (std::size_t i = 0; i < str.size(); i++){
                binaryString += std::bitset<8>(str[i]).to_string();
            }
            return  binaryString;
        }

        static int Tina_is_palindrome(std::string strr, int Tina_return_bool_){
            std::string p = strr;
            std::string l = Tina_reverseString(p);
            if(l == p){
                return true; 
            }else{
                return false;
            }  

        }

        static std::string input(const std::string& prompt){
            std::string user_message;
            std::cout << prompt;
            std::getline(std::cin, user_message);
            return user_message;
        }

    private:


    
    };


}
/*
Compilation : 
g++ -o t.exe t.cpp
*/
