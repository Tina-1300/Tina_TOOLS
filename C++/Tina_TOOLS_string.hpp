/**
 * @file Tina_TOOLS_string.hpp
 * @brief Cette class permet de gérez la librarie les chaine de caractère 
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o test.exe test.cpp
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * - 
 * 
 * Fichier .hpp qui et utiliser par la classe :
 * - aucun 
 *
 * Disponibilité :
 * - Windows
 * 
 * @note Assurez-vous d'avoir les lib sur vôtre système sinon installer les lib nécessaire.
 * 
 * 
 * @author Tina
 * @date 28/07/2024
 * @version 0.2
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/

#ifndef Tina_TOOLS_string_
#define Tina_TOOLS_string_


#ifdef _WIN32
#include <windows.h>
#endif

// Autres inclusion
#include <iostream>
#include <string>
#include <algorithm> // reverse
#include <bitset> // pour le binaire ce renseigner sur la doc 

/**
 * @def CONSOLE_UTF8
 * @brief permet d'afficher les caractère en UTF_8
 */
#define CONSOLE_UTF8 SetConsoleOutputCP(65001)


/**
 * @def Tina_TRUE
 * @brief permet de renvoyer 84 si ses juste
 */
#define Tina_TRUE 84


/**
 * @def Tina_FALSE
 * @brief permet de renvoyer 34 si ses faux
 */
#define Tina_FALSE 34

/**
 * @def Tina_return_bool
 * @brief permet d'utiliser Tina_TRUE et Tina_False
 */
#define Tina_return_bool 43



class Tina_TOOLS_string{
private:


public:
    /**
     * @fn Tina_reverseString()
     * @param [std::string str] attend une chaine de caractère qui et la chaine de caractère a inverser
     * @note Cette fonction permet de d'inverser une chaine de caractère
     * 
     * Cette fonction permet de d'inverser une chaine de caractère
     * 
     * Example d'utilisation : 
     * 
     * ```c
     * #include <iostream>
     * #include "Tina_TOOLS/Tina_TOOLS_string.hpp"
     * 
     * 
     * int main(){
     *     Tina_TOOLS_string tina_str;
     *     std::cout << tina_str.Tina_reverseString("Tina") << std::endl;
     * 
     *     return 0; 
     * }
     * ```
    */
    static std::string Tina_reverseString(std::string str){
        std::reverse(str.begin(), str.end());
        return str;
    }
    
    /**
     * @fn Tina_Compare()
     * @param [std::string str] attend une chaine de caractère a comparer 
     * @param [const char *str_a_comparer] attend la chaine de caractère a comparer a la première 
     * @note Cette fonction permet de comparer la chaine de caractère du premier paramètre au second
     * 
     * Cette fonction permet de comparer la chaine de caractère du premier paramètre au second
     * 
     * Example d'utilisation : 
     * 
     * ```c
     * #include <iostream>
     * #include "Tina_TOOLS/Tina_TOOLS_string.hpp"
     * 
     * int main(){
     *     Tina_TOOLS_string tina_str;
     *     std::string p = "de";
     *     const char *t = "de";
     *     if(tina_str.Tina_Compare(p, t)){
     *         std::cout << "juste" << std::endl;
     *     }else{
     *         std::cout << "faux" << std::endl;
     *     }
     * 
     *     return 0; 
     * }
     * ```
    */
    static int Tina_Compare(std::string str, const char *str_a_comparer){
        if(str.compare(str_a_comparer) == 0){
            return Tina_TRUE;
        }else{
            return Tina_FALSE;
        }
    }

    /**
     * @fn Tina_convert_string_to_binary()
     * @param [std::string str] attend une chaine de caractère a comparer 
     * @note Cette fonction permet de traduire une chaine de caractère en binaire
     * 
     * Cette fonction permet de traduire une chaine de caractère en binaire
     * 
     * Example d'utilisation : 
     * 
     * ```c
     * #include <iostream>
     * #include "Tina_TOOLS/Tina_TOOLS_string.hpp"
     * 
     * int main(){
     *     Tina_TOOLS_string tina_str;
     *     std::string p = "de";
     *     std::cout << tina_str.Tina_convert_string_to_binary(p) std::endl;
     * 
     *     return 0; 
     * }
     * ```
    */
    static std::string Tina_convert_string_to_binary(std::string str){
        std::string  binaryString;
        for (std::size_t i = 0; i < str.size(); i++){
            //std::cout << std::bitset<8>(str[i]) << std::endl;
            binaryString += std::bitset<8>(str[i]).to_string();
        }
        return  binaryString;
    }

    /**
     * @fn Tina_is_palindrome()
     * @param [std::string strr] attend une chaine de caractère a vérifier si il et palindrom
     * @param [int Tina_return_bool_] et pas obligatoir mais si vous l'utiliser en mettant Tina_return_bool aulieu de retourner le mot entre il returnera Tina_TRUE ou Tina_FALSE
     * @note Cette fonction et une function surcharger qui permet de voir si un mot et palindrom
     * 
     * Cette fonction et une function surcharger qui permet de voir si un mot et palindrom
     * 
     * Example d'utilisation 2 : 
     * 
     * ```c
     * #include <iostream>
     * #include "Tina_TOOLS/Tina_TOOLS_string.hpp"
     * 
     * int main(){
     *     Tina_TOOLS_string tina_str;
     *     std::string p = "txt";
     *     std::cout << tina_str.Tina_is_palindrome(p) << std::endl;
     * 
     *     // et la si le mot et palindrom il renvoi le mot passer en paramètre sinon il renvoi "is note palindrome"
     * 
     *     return 0; 
     * }
     * ```
    */
    static int Tina_is_palindrome(std::string strr, int Tina_return_bool_){
        if(Tina_return_bool){
            std::string p = strr;
            std::string l = Tina_reverseString(p);
            if(l == p){
                return Tina_TRUE; 
            }else{
                return Tina_FALSE;
            }
        }

    }

};



/*
Compilation : 
g++ -o t.exe t.cpp
*/

#endif