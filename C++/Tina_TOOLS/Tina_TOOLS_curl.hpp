/**
 * @file Tina_TOOLS_curl.hpp
 * @brief Cette class permet de gérez la librarie curl  
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o t.exe t.cpp -lcurl
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * - curl
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
 * @date 27/08/2024
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/
#ifndef Tina_TOOLS_curl_
#define Tina_TOOLS_curl_


// En-têtes CURL
#include <curl/curl.h>

// Autres inclusion
#include <iostream>
#include <string>


/**
 * @def ERROR_EMPTY_URL
 * @brief permet de renvoyer un statu de 32 si il y a pas d'url
 */
#define ERROR_EMPTY_URL 32

/**
 * @def UE
 * @brief permet de renvoyer un statu de -1 si il y a une error non déini
 */
#define UE -1

class Tina_TOOLS_curl{
private:
    static void Skip_SSL_Certificate_Verification(CURL* curl){
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    }

    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream){
        size_t written = fwrite(ptr, size, nmemb, stream);
        return written;
    }

public:

    static long Tina_Get_STATUS_HTTP_URL(std::string URL){
        CURL* curl;
        CURLcode res;
        long http_code = 0;
        curl = curl_easy_init();
        
        if(curl){
            if (URL.empty()){
                std::cerr << "erreur : URL vide" << std::endl;
                return ERROR_EMPTY_URL; 
            }
            curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

            // ignorer la verification du certificat
            Skip_SSL_Certificate_Verification(curl);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1); 
            res = curl_easy_perform(curl);
            if (res != CURLE_OK){
                std::cerr << "curl_easy_perform() failed : " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                return UE; 
            }else{
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            }
            curl_easy_cleanup(curl);
        }else{
            std::cerr << "Erreur : Impossible d'initialiser CURL." << std::endl;
            return UE; 
        }
        return http_code;
            
    }


    static void Tina_Download_File(const std::string& url, const std::string& outputFile){
        CURL *curl;
        FILE *fp;
        CURLcode res;
        curl = curl_easy_init();
        if (curl){
            fp = fopen(outputFile.c_str(), "wb");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            // ignorer la verification du certificat
            Skip_SSL_Certificate_Verification(curl);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);

            if (res != CURLE_OK){
                std::cerr << "Erreur lors du téléchargement : " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                fclose(fp);
            }
            curl_easy_cleanup(curl);
            fclose(fp);
        }
    }


};

/*
Compilation : 
g++ -o t.exe t.cpp -lcurl
*/

#endif