#pragma once
//permet d'avoir accès à print() et à input() de python

#include <iostream>
#include <string>

namespace Tina{

    namespace Python{

        std::string input(const std::string& prompt){
            std::string user_message;
            std::cout << prompt;
            std::getline(std::cin, user_message);
            return user_message;
        }

        template<typename T>
        void print(const T& first){
            std::cout << first << std::endl;
        }

        template<typename T, typename... Args>
        void print(const T& first, const Args&... rest){
            std::cout << first << " ";
            print(rest...); 
        }

        void space(int number_line){
            for (int i = 0; i != number_line; i++){
                std::cout << std::endl;
            }
        }
    


    }
}