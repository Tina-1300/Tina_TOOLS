#pragma once


#include <windows.h>

namespace Tina{

    class Tina_Reg{
    public:

        static void StartMorning(const WCHAR * NameKey, const WCHAR * FilePath){
            HKEY hKey;
            RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
            DWORD filePathSize = (wcslen(FilePath) + 1) * sizeof(WCHAR);
            RegSetValueExW(hKey, NameKey, 0, REG_SZ, (const BYTE*)FilePath, filePathSize); // L"Youtube" L"C:\\Youtube.exe"
            RegCloseKey(hKey);
        }

        static void DeletStartMorning(const WCHAR * NameKey){
            HKEY hKey;
            RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
            RegDeleteValueW(hKey, NameKey);
            RegCloseKey(hKey);
        }

       

        // Marche a la perfection a Ajouter dans la doc
        static void AddKeyRegister(const WCHAR * NameKey, const WCHAR * FilePath, const wchar_t * Register){
            HKEY hKey;
            RegOpenKeyW(HKEY_CURRENT_USER, Register, &hKey);
            DWORD filePathSize = (wcslen(FilePath) + 1) * sizeof(WCHAR);
            RegSetValueExW(hKey, NameKey, 0, REG_SZ, (const BYTE*)FilePath, filePathSize); // L"Youtube" L"C:\\Youtube.exe"
            RegCloseKey(hKey);
        }

        // Marche à la perfection a ajouter a la doc 
        static void DeletKeyRegister(const WCHAR * NameKey, const wchar_t * Register){
            HKEY hKey;
            RegOpenKeyW(HKEY_CURRENT_USER, Register, &hKey);
            RegDeleteValueW(hKey, NameKey); // entre la cle qui stock la valeur dans le registre
            RegCloseKey(hKey);
        }
    
    private:


    };


};

/*
Compilation : 
g++ -o t.exe t.cpp 
*/
