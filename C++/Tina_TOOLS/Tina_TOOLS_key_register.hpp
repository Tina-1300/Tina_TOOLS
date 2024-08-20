/**
 * @file Tina_TOOLS_key_register.hpp
 * @brief Cette class permet de gérez les cle de registre sous windows 
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o test.exe test.cpp 
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * 
 * Fichier .hpp ou h qui et utiliser par la classe :
 * - aucun
 *
 * Disponibilité :
 * - Windows
 * 
 * @note Assurez-vous d'avoir les lib sur vôtre système sinon installer les lib nécessaire.
 * 
 * @author Tina
 * @date 11/08/2024
 * @version 0.1
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/
#ifndef Tina_TOOLS_key_register_
#define Tina_TOOLS_key_register_

//#include <iostream>
#include <windows.h>



class Tina_Reg{
private:


public:

    /**
     * @fn StartMorning()
     * @param [const WCHAR * NameKey] Attend un paramètre de type chaine de caractère qui et le nom de la cle 
     * @param [const WCHAR * FilePath] Attend un paramètre de type chaine de caractère qui et le chemin du .exe 
     * 
     * @note Cette fonction permet d'ajouter un fichier dans Software\\Microsoft\\Windows\\CurrentVersion\\Run pour lancer a chaque démarage du programme le fichier
     * 
     * Example d'utilisation : 
     * @warning l'example de cette fonction ce trouve dans la documentation
     */
    static void StartMorning(const WCHAR * NameKey, const WCHAR * FilePath){
        HKEY hKey;
        RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
        RegSetValueExW(hKey, NameKey, 0, REG_SZ, (const BYTE*)FilePath, sizeof(FilePath)); // L"Youtube" L"C:\\Youtube.exe"
        RegCloseKey(hKey);
    }

    /**
     * @fn DeletStartMorning()
     * @param [const WCHAR * NameKey] Attend un paramètre de type chaine de caractère qui et le nom de la cle a suprimmer
     * 
     * @note Cette fonction permet de supprimer une cle de registre dans Software\\Microsoft\\Windows\\CurrentVersion\\Run
     * 
     * Example d'utilisation : 
     * @warning l'example de cette fonction ce trouve dans la documentation
     */
    static void DeletStartMorning(const WCHAR * NameKey){
        HKEY hKey;
        RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
        RegDeleteValueW(hKey, NameKey);
        RegCloseKey(hKey);
    }

};

/*
Compilation : 
g++ -o t.exe t.cpp 
*/

#endif