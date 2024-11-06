#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>



namespace Tina{
    

    class Clara_vector{
    public: 

        //https://en.cppreference.com/w/cpp/container/map
        // cree une fonction pour calculer la moyenne pondéré via les dictionnaire map et les tableau 
        // améliorer la méthode ArrayMoyennePondere_Clara
        template <typename T, typename Note, typename Coef, typename SomOfProduit, typename SomOfCoef>
        static T ArrayMoyennePondere_Clara(const std::map<Note, Coef>& dico){
            SomOfProduit SommOfProduit = 0;
            SomOfCoef SommeOfCoef = 0;
            for (const auto& [note, coef] : dico){
                SommOfProduit += note * coef;
                SommeOfCoef += coef;
            }   
            return SommOfProduit / SommeOfCoef;
        };




        template <typename T>
        static T ArrayMoyenne_Clara(const std::vector<T>& vec){
            if (vec.empty()){
                std::cerr << "Erreur : le tableau est vide, impossible de calculer la moyenne." << std::endl;
                return T{};
            }
            
            T sum;
            for (const T& num : vec){
                sum += num;
            }
            return sum / vec.size();
        };

        // mettre ArrayMoyenne_Clara dans les math 

        template <typename T>
        static T ArraySum_Clara(const std::vector<T>& vec){
            if (vec.empty()){
                std::cerr << "Erreur : le tableau est vide, impossible de calculer la moyenne." << std::endl;
                return T{};
            }

            T sum;
            for (const T& num : vec){
                sum += num;
            }
            return sum;
        };

        template <typename T>
        static T ArrayQuotient_Clara(const std::vector<T>& vec){
            T quotient;
            for (T num : vec){
                quotient /= num;
            }
            return quotient;
        };

        template <typename T>
        static T ArrayDifference_Clara(const std::vector<T>& vec){
            T difference;
            for (T num : vec){
                difference -= num;
            }
            return difference;
        };

        template <typename T>
        static T ArrayProduit_Clara(const std::vector<T>& vec){
            T produit;
            for (T num : vec){
                produit *= num;
            }
            return produit;
        };

        // return le nombre d'élément du tableau si example le tableau à 8 element alor vous cerais qu'il y a l'index 0 à 8
        template <typename T>
        static int ArrayIndexSearch_Clara(const std::vector<T>& vec){
            int result = 0;
            for (int i = 0; i < vec.size(); i++){
                result += i;
            }
            return result;
        };

        template <typename T>
        static void ArrayDisplayAll_Clara(const std::vector<T>& vec){
            for (int i = 0; i < vec.size(); i++){
                std::cout << i << " : " << vec[i] << std::endl;
            }
        };

        template <typename T>
        static void ArrayDisplayIndex_Clara(const std::vector<T>& vec){
            int numindex = 0;
            for (int i = 0; i < vec.size(); i++){
                numindex += i;
            }
            std::cout << numindex <<std::endl;
            
        };
        
        template <typename T>
        static int ArraySearch_Clara(const std::vector<T>& vec, const T& search){
            for (int i = 0; i < vec.size(); i++){
                if(search == vec.at(i)){
                    return i;
                }
            }
            return -1; // pas trouver 
        }

        template <typename T>
        static int ArrayDelet_Clara(const std::vector<T>& vec, const T& delet){
            for (int i = 0; i < vec.size(); i++){
                if(delet == vec.at(i)){
                    vec.erase(vec.begin() + i);
                }
            }
            return -1;// pas trouver
        }



        // fonction qui permet de copier tous le contenu d'un tableau d'en un autre tableau et si delet_or_copy et à true 
        // on transfer tous au tableau et on suprimme en même temps le contenu du tableau d'origin si ses à false
        // on copi juste la tableau d'origine dans l'autre tableau
        template <typename T>
        static int CopiTableau(std::vector<T> vec, std::vector<T> tableau_copi_finaly, bool delet_or_copy){
            for (int i = 0; i < vec.size(); i++){
                if(delet_or_copy == false){
                    tableau_copi_finaly.push_back(vec.at(i));
                }else if (delet_or_copy == true){
                    tableau_copi_finaly.push_back(vec.at(i));
                    vec.erase(vec.at(i));
                }
            }
            return 0;// tous ses bien passer
        }




    };


} 
/*
compilation : 
g++ -o fk.exe fk.cpp 
*/