/**
 * @file Tina_TOOLS_sha.hpp
 * @brief Cette class permet de gérez la famille des sha elle traite les SHA-1, SHA-224, SHA-256, SHA-384, SHA-512  
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o t.exe t.cpp -lssl -lcrypto -lws2_32 -lbcrypt
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * - openssl
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
 * @date 29/07/2024
 * @version 0.2
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/

#ifndef TINA_TOOLS_sha_
#define TINA_TOOLS_sha_

// en-tête systeme
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>

// En-têtes OpenSSL
#include <openssl/sha.h>


// Autres inclusion
#include <iostream>
#include <iomanip> // Pour std::hex et std::setw
#include <sstream> // Pour std::stringstream
#include <cstring> // Pour std::strlen


class Tina_TOOLS_sha{
private:
    static std::string hashToString(const unsigned char *hash, size_t length){
        std::stringstream ss;
        for (size_t i = 0; i < length; ++i){
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }
        return ss.str();
    }


public:

    /**
     * @fn Hash_STRING_SHA__()
     * @param [std::string message] attend une chaine de caractère du message a hasher
     * @param [size_t choice_hash] attend un type entier non signé qui indique le sha a utiliser pour hasher le message
     * @note Cette fonction permet de hasher une chaine de caractère avec la famille sha 
     * 
     * 
     * Cette fonction permet de hasher un message et de le retourner
     * 
     * Example d'utilisation : 
     * 
     * ```c
     *  #include <iostream>
     *  #include "Tina_TOOLS/Tina_TOOLS_sha.hpp"
     * 
     * int main(){
     *     CONSOLE_UTF8;
     *     Tina_TOOLS_sha sha_tin;
     *     std::string message_urg = "Tina";
     *     std::cout << "sha Tina 512 : " << sha_tin.Hash_STRING_SHA__(message_urg, SHA512_DIGEST_LENGTH) << std::endl; 
     *     
     *      // sha-1 = SHA_DIGEST_LENGTH
     *     // sha-224 = SHA224_DIGEST_LENGTH
     *    // sha-256 = SHA256_DIGEST_LENGTH
     *   // sha-384 = SHA384_DIGEST_LENGTH
     *  //  sha-512 = SHA512_DIGEST_LENGTH
     *     return 0; 
     * }
     * ```
    */
    static std::string Hash_STRING_SHA__(std::string message, size_t choice_hash){
        std::string text_to_hash = message;
        unsigned char hash[choice_hash];
        
        if(choice_hash == SHA256_DIGEST_LENGTH){
            // Calcul du hachage SHA-256
            SHA256(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash);
        }else if (choice_hash == SHA512_DIGEST_LENGTH){
            // Calcule du hash SHA-512
            SHA512(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash);
        }else if (choice_hash == SHA_DIGEST_LENGTH){
            // Calcule du SHA-1
            SHA1(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash);
        }else if (choice_hash == SHA224_DIGEST_LENGTH){
            // Calcule du SHA-224
            SHA224(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash);
        }else if (choice_hash == SHA384_DIGEST_LENGTH){
            // Calcule du SHA-384
            SHA384(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash);
        }else{
            MessageBoxW(NULL, L"Vous avez mal utiliser la fonction", L"Error", MB_ICONERROR | MB_OK);
        }
        std::string hash_str = hashToString(hash, choice_hash);
        return hash_str;
    }


};

/*
compilation : 
g++ -o t.exe t.cpp -lssl -lcrypto -lws2_32 -lbcrypt & color 4

Documentation Openssl C++ : 
https://docs.openssl.org/master/
*/

#endif