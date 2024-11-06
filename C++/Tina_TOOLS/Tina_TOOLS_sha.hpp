#ifndef TINA_TOOLS_sha_
#define TINA_TOOLS_sha_

// en-tête systeme
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>

// En-têtes OpenSSL
#include <openssl/sha.h>



#include <iostream>
#include <iomanip> // Pour std::hex et std::setw
#include <sstream> // Pour std::stringstream
#include <cstring> // Pour std::strlen
#include <vector> 

namespace Tina{

class Tina_TOOLS_sha{

    public:

        static std::string Hash_STRING_SHA__(std::string message, size_t choice_hash){
            std::string text_to_hash = message;
            std::vector<unsigned char> hash(choice_hash);  // Utilisation d'un vectore pour la taille dynamique

            if(choice_hash == SHA256_DIGEST_LENGTH){
                SHA256(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash.data());
            }else if (choice_hash == SHA512_DIGEST_LENGTH){
                SHA512(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash.data());
            }else if (choice_hash == SHA_DIGEST_LENGTH){
                SHA1(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash.data());
            }else if (choice_hash == SHA224_DIGEST_LENGTH){
                SHA224(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash.data());
            }else if (choice_hash == SHA384_DIGEST_LENGTH){
                SHA384(reinterpret_cast<const unsigned char*>(text_to_hash.c_str()), text_to_hash.length(), hash.data());
            }else{
                MessageBoxW(NULL, L"Vous avez mal utiliser la fonction", L"Erreur", MB_ICONERROR | MB_OK);
            }
            return hashToString(hash.data(), choice_hash);
        }



    private:

        static std::string hashToString(const unsigned char *hash, size_t length){
            std::stringstream ss;
            for (size_t i = 0; i < length; ++i){
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
            }
            return ss.str();
        }

        

};



}



/*
compilation : 
g++ -o t.exe t.cpp -lssl -lcrypto -lws2_32 -lbcrypt & color 4

Documentation Openssl C++ : 
https://docs.openssl.org/master/
*/

#endif