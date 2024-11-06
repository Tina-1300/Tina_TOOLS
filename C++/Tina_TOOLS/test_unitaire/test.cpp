#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include "../Tina_TOOLS_curl.hpp"



int main(){
    SetConsoleOutputCP(CP_UTF8);
    std::string url = "http://192.168.1.188:3000/params";
    Tina::Curling::Params parameters = { {"pseudo", "Alex"}, {"password", "testAlex"} };
    std::string send_param = Tina::Curling::params_string(parameters);
    
    if (Tina::Curling::post(url, send_param) == true){
        std::cout << "Requête PUT reussie." << std::endl;
    } else{
        std::cout << "Échec de la requete PUT." << std::endl;
    }
    return 0;
}
// g++ -o test.exe test.cpp -lcurl