/**
 * @file TINA_TOOLS_FILE_READ.hpp
 * @brief Cette class permet de gérez la lecture de fichier en mode binaire, et pourra le faire en mode hexadecimal, et octal 
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
 * @date 30/07/2024
 * @version 0.2
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/

#ifndef TINA_TOOLS_FILE_READ_
#define TINA_TOOLS_FILE_READ_

#include <iostream>
#include <fstream>
#include <bitset> // pour le binaire 
#include <sys/stat.h>


class TINA_TOOLS_FILE_READ{
private:
    /**
     * @fn tina_file_exists()
     * @param [const std::string& filePath] attend une chaine de caractère en paramètre pour le chemin du fichier
     * @note Cette fonction permet de vérifier l'exsistance d'un fichier
     */
    static bool tina_file_exists(const std::string& filePath){
        struct stat buffer;
        return (stat(filePath.c_str(), &buffer) == 0);
    }


public:

    /**
     * @fn Tina_Read_File_Binary()
     * @param [const std::string& filePath] attens une chaine de caractère en paramètre pour le chemin du fichier
     * @note Cette fonction permet de lire le contenu d'un fichier en mode binaire
     * 
     * Cette fonction permet de lire le contenu d'un fichier en mode binaire
     * 
     * Example d'utilisation de la fonction : 
     * 
     * ```c
     * #include <iostream>
     * #include "Tina_TOOLS/Tina_TOOLS/Tina_TOOLS_FILE_READ.hpp"
     * 
     * int main(){
     *     Tina_TOOLS_FILE_READ tina_read;
     *     std::string filePath = "v.png";
     *     tina_read.Tina_Read_File_Binary(filePath);
     *     return 0;
     * }
     * ```
     */
    static void Tina_Read_File_Binary(const std::string& filePath){
        if (!tina_file_exists(filePath)){
            std::cerr << "Le fichier nexiste pas" << std::endl;
            return;
        }
        std::ifstream file(filePath, std::ios::binary);
        if (!file){
            std::cerr << "erreur d'ouverture" << std::endl;
            return;
        }
        char ch;
        while (file.get(ch)){
            // convertir caractere en valeur binaire
            std::bitset<8> binaryValue(static_cast<unsigned char>(ch));
            //std::cout << binaryValue << ' ';
        }
        file.close();
    }

    // lire un fichier en hexadecimale après 


};

/*
compilation : 
g++ -o t.exe t.cpp 


*/

#endif