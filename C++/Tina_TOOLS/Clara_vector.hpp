/**
 * @file Clara_vector.hpp
 * @brief Cette class permet de géré les tableau vector en C++ 
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o t.exe t.cpp
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * - 
 * 
 * Fichier .hpp ou h qui et utiliser par la classe :
 * - aucun
 *
 * Disponibilité :
 * - Windows
 * 
 * @note Assurez-vous d'avoir les lib sur vôtre système sinon installer les lib nécessaire.
 * 
 * 
 * @author Tina
 * @date 16/08/2024
 * @version 0.1
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/

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

doc : 
https://www.youtube.com/watch?v=Ob-H9dd2y4Y&list=PL0ibd6OZI4XKMwaPS1xHU9N_smy3AkcUr&index=53

*/

#endif