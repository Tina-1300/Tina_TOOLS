#ifndef Clara_vector_
#define Clara_vector_

#include <iostream>
#include <vector>
#include <string>

#define Not_Found -808
#define SUCESS_RETURN -700

class Clara_vector{
public: 
    static void DisplayAllTab(const std::vector<std::string>& vec){
        for (int i = 0; i < vec.size(); i++){
            std::cout << i << " : " << vec[i] << std::endl;
        }
    }

    static void DisplayTAB(const std::vector<std::string>& vec){
        for (int i = 0; i < vec.size(); i++){
            std::cout << vec.at(i) << std::endl;
        } 
    }

    static int SeartchTAB(const std::vector<std::string>& vec, const std::string search_cara){
        for (int i = 0; i < vec.size(); i++){
            if(search_cara == vec.at(i)){
                return i;
            }
        }
        return Not_Found; // -808
    }

    static int DeletTAB(std::vector<std::string>& vec, const std::string delet_cara){
        for (int i = 0; i < vec.size(); i++){
            if(delet_cara == vec.at(i)){
                vec.erase(vec.begin() + i);
            }
        }
        return Not_Found; // -808
    }

};


/*
compilation : 
g++ -o fk.exe fk.cpp 
*/

#endif