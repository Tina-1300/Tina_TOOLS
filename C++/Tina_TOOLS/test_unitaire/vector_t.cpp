#include <iostream>
#include <map>
#include <vector>
#include "../Clara_vector.hpp"

int main(){
    
    Tina::Clara_vector clara;
    std::map<double, double> dico = {{17, 2}, {13, 3}, {15, 1}, {18, 4}};
    auto res = clara.ArrayMoyennePondere_Clara<double, double, double, double, double>(dico);
    std::cout << res << std::endl;


    return 0;
}