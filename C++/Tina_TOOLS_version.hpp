/**
 * @file Tina_TOOLS_version.hpp
 * @brief Cette class permet d'avoir des info sur la librarie
 * 
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o test.exe test.cpp
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * 
 * Fichier .hpp qui et utiliser par la classe :
 * - aucun 
 *
 * Disponibilité :
 * - Windows
 * - Linux
 * 
 * @note Assurez-vous d'avoir les lib sur vôtre système sinon installer les lib nécessaire.
 * 
 * 
 * @author Tina
 * @date 28/07/2024
 * @version 0.2
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/

#ifndef Tina_TOOLS_version_
#define Tina_TOOLS_version_

#include <iostream>


class Tina_TOOLS_version{
private:


public:
    /**
     * @fn Version()
     * @note Cette fonction indique la version de la librairie 
     * 
     * Cette fonction affiche dans le terminal la version de la librairie 
     * 
     * Example d'utilisation : 
     * 
     * ```c
     * #include #include "Tina_TOOLS/Tina_TOOLS_version.hpp"
     * 
     * int main(){
     *     CONSOLE_UTF8;
     *     Tina_TOOLS_version info;
     *     info.Version();   
     *     return 0; 
     * }
     * ```
    */
    static void Version(){
        std::cout << "Version : 0.2" << std::endl;
    }


};



#endif