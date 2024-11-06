#pragma once

#include <curl/curl.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#define ERROR_EMPTY_URL 32
#define UE -1

namespace Tina{
    namespace Curling{
        
        void Skip_SSL_Certificate_Verification(CURL* curl){
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        }

        size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream){
            return fwrite(ptr, size, nmemb, stream);
        }

        long GetStatus(const std::string& URL){
            if (URL.empty()){
                std::cerr << "Erreur : URL vide." << std::endl;
                return ERROR_EMPTY_URL; 
            }

            CURL* curl = curl_easy_init();
            if (!curl){
                std::cerr << "Erreur : Impossible d'initialiser CURL." << std::endl;
                return UE; 
            }

            long http_code = 0;
            curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
            Skip_SSL_Certificate_Verification(curl);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1); 

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK){
                std::cerr << "curl_easy_perform() failed : " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                return UE; 
            }else{
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            }
            curl_easy_cleanup(curl);
            return http_code;
        }

        int download(const std::string& url, const std::string& outputFile){
            if (url.empty()){
                std::cerr << "Erreur : URL vide." << std::endl;
                return ERROR_EMPTY_URL;
            }

            CURL* curl = curl_easy_init();
            if (!curl){
                std::cerr << "Erreur : Impossible d'initialiser CURL." << std::endl;
                return UE; 
            }

            FILE* fp = fopen(outputFile.c_str(), "wb");
            if (!fp){
                std::cerr << "Erreur lors de l'ouverture du fichier : " << outputFile << std::endl;
                curl_easy_cleanup(curl);
                return 1; 
            }

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            Skip_SSL_Certificate_Verification(curl);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK){
                std::cerr << "Erreur lors du téléchargement : " << curl_easy_strerror(res) << std::endl;
                fclose(fp);
                curl_easy_cleanup(curl);
                return 2; 
            }
            
            fclose(fp);
            curl_easy_cleanup(curl);
            return 0; 
        }

        bool get(const std::string& url, const std::string& params){
            if (url.empty()) {
                std::cerr << "Erreur : URL vide." << std::endl;
                return false; 
            }

            CURL* curl = curl_easy_init();
            if (!curl) {
                std::cerr << "Erreur : impossible d'initialiser CURL." << std::endl;
                return false;
            }

            std::string full_url = url + "?" + params;
            curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
            Skip_SSL_Certificate_Verification(curl);
            
            CURLcode res = curl_easy_perform(curl);
            bool success = (res == CURLE_OK);
            if (!success){
                std::cerr << "Erreur de requete GET : " << curl_easy_strerror(res) << std::endl;
            }
            curl_easy_cleanup(curl);
            return success; 
        }

        bool post(const std::string& url, const std::string& params){
            if (url.empty()) {
                std::cerr << "Erreur : URL vide." << std::endl;
                return false; 
            }

            CURL* curl = curl_easy_init();
            if (!curl) {
                std::cerr << "Erreur : impossible d'initialiser CURL." << std::endl;
                return false;
            }

            std::string full_url = url + "?" + params;
            curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
            Skip_SSL_Certificate_Verification(curl);
            
            CURLcode res = curl_easy_perform(curl);
            bool success = (res == CURLE_OK);
            if (!success){
                std::cerr << "Erreur de requete POST : " << curl_easy_strerror(res) << std::endl;
            }
            curl_easy_cleanup(curl);
            return success; 
        }

        bool put(const std::string& url, const std::string& params){
            if (url.empty()) {
                std::cerr << "Erreur : URL vide." << std::endl;
                return false; 
            }

            CURL* curl = curl_easy_init();
            if (!curl) {
                std::cerr << "Erreur : impossible d'initialiser CURL." << std::endl;
                return false;
            }

            std::string full_url = url + "?" + params;
            curl_easy_setopt(curl, CURLOPT_PUT, params.c_str());
            curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
            Skip_SSL_Certificate_Verification(curl);
            
            CURLcode res = curl_easy_perform(curl);
            bool success = (res == CURLE_OK);
            if (!success){
                std::cerr << "Erreur de requete PUT : " << curl_easy_strerror(res) << std::endl;
            }
            curl_easy_cleanup(curl);
            return success; 
        }


        typedef std::vector<std::pair<std::string, std::string>> Params;
        std::string params_string(const Params& params){
            if (params.empty()){
                return "";  
            }
            std::string data;
            for (const auto& pair : params){
                if (!data.empty()){
                    data += "&"; 
                }
                data += pair.first + "=" + pair.second; 
            }
            return data;  
        }

    } // namespace Curling
} // namespace Tina
