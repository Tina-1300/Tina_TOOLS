#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#define Kelvin_ 273.15
#define PI 3.14159265358979323846264338327950288419716939937510582 
#define E 2.718281828459045
#define LN2 0.6931471805599453
#define LN10 2.302585092994046
#define LOG2E 1.4426950408889634
#define LOG10E 0.4342944819032518
#define SQRT1_2 0.7071067811865476
#define SQRT2 1.4142135623730951



namespace Mathematique{

    // ajouter ça a la documentation cette structures
    namespace StructuresMath{

        // pour la v 0.7 ajouter un autre typename pour le denominateur
        template <typename T>
        struct Fraction{
            T numerateur;
            T denominateur;
        };

        template <typename T, typename U, typename V, typename W>
        struct ProduitInCroix{
            T A1; V A2;
            U B1; W B2;
        };

    };


    namespace Theoreme{

        namespace Pythagore{

            template <typename T>
            T Hypotenuse(T a, T b){
                return sqrt(pow(a, 2) + pow(b, 2));  // entre les deux côté pour trouver l'hypoténus 
            };

            template <typename T> // paramètre OP le plus grand côté , les deux autre paramètre sont les autres valeur 
            bool IsRectangle(T OP, T PN, T NO){
                T result_OP, pn, no, result;
                result_OP = pow(OP, 2);
                pn = pow(PN, 2);no = pow(NO, 2);
                result = pn + no;
                if(result_OP == result){
                    return true; 
                }else{
                    return false;
                }

            };


            template <typename T>
            T AdjacentSide(T hypotenuse, T otherSide){ // paramètre hypoténus, un  côté pour retrouver le coté manquant
                return sqrt(pow(hypotenuse, 2) - pow(otherSide, 2));
            };


        };
    };


    // a declarer dans la doc
    namespace Calcule{

        // ajouter a la doc DistanceTimeSpeed
        namespace DistanceTimeSpeed{

            template <typename T>
            T Distance(T vitesse, T temps){
                return vitesse * temps;
            };

            template <typename T>
            T Temps(T distance, T vitesse){
                return distance / vitesse;
            };

            template <typename T>
            T Vitesse(T distance, T temps){
                return distance / temps;
            };

        };
        // fin du namespace a ajouter a la doc

        
        int factorielle(int number){
            if(number < 0){
                return -1; // error la factorielle n'est pas définie pour les nombres négatifs.
            }else if(number == 0){
                return 1; //  la factorielle de 0 s'est 1
            }else{
                int resultat = 1;
                for (int i = 1; i <= number; ++i){
                    resultat *= i; 
                }
                return resultat; // return la factorielle du nombre sous forme de int
            }
        };


        template <typename T>
        std::vector<T> DivisorVect(T number){
            if(number <= 0){
                return {};
            }else{
                std::vector<T> result = {};
                for (T i = 1; i <= number; ++i){
                    if (number % i == 0) {
                        result.push_back(i);
                    }
                }
                return result;
            }
        };

        
        bool IsPairOrImpair(int n){
            if(n %2 ==0){
                return true; // le nombre et paire
            }else{
                return false; // le nombre et impaire
            }
        };

        bool IsPremier(int n){
            if (n <= 1){
                return false;
            }else{
                for (int i = 2; i<= std::sqrt(n); ++i){
                    if (n % i == 0){
                        return false; // Retourne false si n n'est pas premier
                    }
                }
                return true; // le nombre et premier
            }
        };

 

        template <typename T>
        T isPuissanceNumber(T number, T table){
            int count = 0;
            while (number > 1){
                number/=table;
                count++;
            }
            return count;
            
        };

        // a regarder si ses dans la doc si non y ajouter 
        // ---------------------------------------------------------------------------------
        /*
            T A1; V A2;
            U B1; W B2;
        */

        
        template <typename T, typename U, typename V, typename W, typename SearchX>
        Mathematique::StructuresMath::ProduitInCroix<T, V, U, W> ProduitInCroixCalculat(Mathematique::StructuresMath::ProduitInCroix<T, V, U, W> A1, SearchX X){
            Mathematique::StructuresMath::ProduitInCroix<T, V, U, W> result;

            if(X == 1){//A1 si le deuxième paramètre de la fonction et a 1 alor c'est A1 x et on fait ce calcule
                result.A1 = A1.A2 * A1.B1 / A1.B2;
            }
            if(X == 2){//A2 si le deuxième paramètre de la fonction et a 1 alor c'est A2 x et on fait ce calcule
                result.A2 = A1.A1 * A1.B2 / A1.B1;
            }
            if(X == 3){ //B1 si le deuxième paramètre de la fonction et a 1 alor c'est B1 x et on fait ce calcule
                result.B1 = A1.B2 * A1.A1 / A1.A2;
            }
            if(X == 4){//B2 si le deuxième paramètre de la fonction et a 1 alor c'est B2 x et on fait ce calcule
                result.B2 = A1.B1 * A1.A2 / A1.A1;
            }
            return result;
        };

        // -----------------------------------------------------------------------------------------------


        
        namespace Fraction{


            template <typename T>
            Mathematique::StructuresMath::Fraction<T> FractionCalculat(const Mathematique::StructuresMath::Fraction<T>& fractionA, const Mathematique::StructuresMath::Fraction<T>& fractionB, std::string methode, bool IsReduce = false){
                Mathematique::StructuresMath::Fraction<T> result;
                if(IsReduce == false){
                    if(methode == "+"){
                        if(fractionA.denominateur == fractionB.denominateur){
                            result.numerateur = fractionA.numerateur + fractionB.numerateur;
                            result.denominateur = fractionA.denominateur;
                        }else{
                            result.numerateur = (fractionA.numerateur * fractionB.denominateur) + (fractionB.numerateur * fractionA.denominateur);
                            result.denominateur = fractionA.denominateur * fractionB.denominateur;
                        }
                    }

                    if(methode == "-"){
                        if(fractionA.denominateur == fractionB.denominateur){
                            result.numerateur = fractionA.numerateur - fractionB.numerateur;
                            result.denominateur = fractionA.denominateur;
                        }else{
                            result.numerateur = (fractionA.numerateur * fractionB.denominateur) - (fractionB.numerateur * fractionA.denominateur);
                            result.denominateur = fractionA.denominateur * fractionB.denominateur;
                        }
                    }

                    if(methode == "*" || methode == "x"){
                        result.numerateur = fractionA.numerateur * fractionB.numerateur;
                        result.denominateur = fractionA.denominateur * fractionB.denominateur;
                    }

                    if(methode == "/"){
                        result.numerateur = fractionA.numerateur * fractionB.denominateur;
                        result.denominateur = fractionA.denominateur * fractionB.numerateur;
                    }

                }else{
                    // rien pour le moment (permettera de réduire au maximum la fraction)
                }
                return result;
            };

        };

    };



    namespace Convertion{

        // Convertion des distance 
        namespace Distance{

            // kilomètre en centimètre
            template <typename T>
            T KmToCm(T longeurKM){
                return longeurKM * 100000;
            };   

            // kilomètre en milimètre
            template <typename T>
            T KmToMm(T longeurKM){
                return longeurKM * 1e+6;
            };

            // kilomètre en décimètre
            template <typename T>
            T KmToDm(T longeurKM){
                return longeurKM * 10000;
            };      

            // kilomètre en mètre
            template <typename T>
            T KmToM(T longeurKM){
                return longeurKM * 1000;
            };

            //kilomètre en décamètre
            template <typename T>
            T KmToDam(T longeurKM){
                return longeurKM * 100;
            };

            // kilomètre en hectomètre
            template <typename T>
            T KmToHm(T longeurKM){
                return longeurKM * 10;
            };

            // hectomère en kilomètre
            template <typename T>
            T HmToKM(T longeurHm){
                return longeurHm / 10;
            };

            //hectomètre en decamètre
            template <typename T>
            T HmToDam(T longeurHm){
                return longeurHm * 10;
            };

            //hectomère en mètre
            template <typename T>
            T HmToM(T longeurHm){
                return longeurHm *100;
            };

            // hectomètre en décimètre
            template <typename T>
            T HmToDm(T longeurHm){
                return longeurHm*1000;
            };

            // héctomètre en centimètre 
            template <typename T>
            T HmToCm(T longeurHm){
                return longeurHm * 10000;
            };

            // héctomètre en milimètre 
            template <typename T>
            T HmToMm(T longeurHm){
                return longeurHm * 100000;
            };

            // décamètre en kilomètre
            template <typename T>
            T DamToKm(T longeurDam){
                return longeurDam / 100;
            };

            // décamètre en hectomètre 
            template <typename T>
            T DamToHm(T longeurDam){
                return longeurDam/10;
            };

            // décamètre en mètre 
            template <typename T>
            T DamToM(T longeurDam){
                return longeurDam * 10;
            };

            // décamètre en decimètre
            template <typename T>
            T DamToDm(T longeurDam){
                return longeurDam * 100;
            };

            // décamètre en centimètre 
            template <typename T>
            T DamToCm(T longeurDam){
                return longeurDam * 1000;
            };

            // décamètre en milimètre
            template <typename T>
            T DamToMm(T longeurDam){
                return longeurDam * 10000;

            };

            // mètre en kilomètre
            template <typename T>
            T MToKm(T longeurM){
                return longeurM / 1000;
            };

            //mètre en hectomètre
            template <typename T>
            T MToHm(T longeurM){
                return longeurM / 100;
            };

            //mètre en decamètre 
            template <typename T>
            T MToDam(T longeurM){
                return longeurM / 10;
            };

            //mètre en decimètre
            template <typename T> 
            T MToDm(T longeurM){
                return longeurM * 10;
            };

            // mètre en centimètre 
            template <typename T>
            T MToCm(T longeurM){
                return longeurM * 100;
            };

            //mètre en milimètre 
            template <typename T>
            T MToMm(T longeurM){
                return longeurM * 1000;
            };

            // décimètre en kilomètre
            template <typename T>
            T DmToKm(T longeurDM){
                return longeurDM / 10000;
            };
        
            //décimètre en hectomètre
            template <typename T>
            T DmToHm(T longeurDM){
                return longeurDM / 1000;
            };

            //décimètre en décamètre 
            template <typename T>
            T DmToDam(T longeurDM){
                return longeurDM / 100;
            };

            // décimètre en mètre 
            template <typename T>
            T DmToM(T longeurDM){
                return longeurDM/10;
            };

            // décimètre en centimètre 
            template <typename T>
            T DmToCm(T longeurDM){
                return longeurDM *10;
            };

            //décimètre en millimètre 
            template <typename T>
            T DmToMm(T longeurDM){
                return longeurDM * 100;
            };

            // centimètre en kilomètre
            template <typename T>
            T CmToKm(T longeurCM){
                return longeurCM / 100000;
            };

            // centimètre en hectomètre
            template <typename T> 
            T CmToHm(T longeurCM){
                return longeurCM / 10000;
            };

            // centimètre en decamètre
            template <typename T> 
            T CmToDam(T longeurCM){
                return longeurCM / 1000;
            };

            // centimètre en mètre 
            template <typename T>
            T CmToM(T longeurCM){
                return longeurCM / 100;
            };  

            // centimètre en décimètre 
            template <typename T>
            T CmToDm(T longeurCM){
                return longeurCM / 10;
            };

            //centimètre en millimètre 
            template <typename T>
            T CmToMm(T longeurCM){
                return longeurCM * 10;
            };  

            // millimètre en kilomètre 
            template <typename T>
            T MmToKm(T longeurMM){
                return longeurMM / 1e+6;
            };

            //millimètre en hectomètre 
            template <typename T>
            T MmToHm(T longeurMM){
                return longeurMM / 100000;
            };

            // millimètre en decamètre 
            template <typename T>
            T MmToDam(T longeurMM){
                return longeurMM / 10000;
            };

            //millimètre en mètre
            template <typename T>
            T MmToM(T longeurMM){
                return longeurMM / 1000;
            };

            // millimètre en décimètre 
            template <typename T>
            T MmToDm(T longeurMM){
                return longeurMM / 100;
            };  

            //millimètre en centimètre 
            template <typename T>
            T MmToCm(T longeurMM){
                return longeurMM / 10;
            };

        };

        namespace Temperatures{

            // degre celsius en Degre fahrenheit
            template <typename T>
            T DegreCelsiusToDegreFahrenheit(T DegreCelsius){
                return (DegreCelsius * 9/5) + 32;
            };

            // degre celsiuse en kelvin
            template <typename T>
            T DegreCelsiusToKelvin(T DegreCelsius){
                return DegreCelsius + Kelvin_;
            };
            // kelvin en degre celsiuse
            template <typename T>
            T KelvinToDegreCelsius(T kelvin){
                return kelvin - Kelvin_;
            };
            // kelvin en degre fahrenheit
            template <typename T>
            T KelvinToDegreFahrenheit(T Kelvin){
                return (Kelvin - Kelvin_) * 9/5 + 32;
            };
            // degre fahrenheit en kelvin 
            template <typename T>
            T DegreFahrenheitToKelvin(T DegreFahrenheit){
                return (DegreFahrenheit - 32) * 5/9 + Kelvin_;
            };
            // degre fahrenheit en degre celsiuse 
            template <typename T>
            T DegreFahrenheitToDegreCelsius(T DegreFahrenheit){
                return (DegreFahrenheit - 32) * 5/9;
            };

        };

        // --------------------------------- à ajouter à la documentation ---------------------------------------------------------
        namespace Temps{
            // siècle en décennie
            template <typename T>
            T SiecleToDecennie(T temps){
                return temps * 10;
            };
            // siècle en année
            template <typename T>
            T SiecleToAnnee(T temps){
                return temps * 100;
            };
            // siècle en Mois 
            template <typename T>
            T SiecleToMois(T temps){
                return temps * 1200;
            };
            // siècle en Semaine
            template <typename T>
            T SiecleToSemaine(T temps){
                return temps * 5214;
            };
            // Siècle en Jour 
            template <typename T>
            T SiecleToJour(T temps){
                return temps * 36500;
            };
            // Siècle en Heur
            template <typename T> 
            T SiecleToHeur(T temps){
                return temps * 876000;
            };
            // siècle en minutes
            template <typename T>
            T SiecleToMinute(T temps){
                return temps * 5.256e+7;
            };
            // siècle en seconde
            template <typename T>
            T SiecleToSeconde(T temps){
                return temps * 3.154e+9;
            };
            //siècle en milisecondes
            template <typename T>
            T SiecleToMilliSeconde(T temps){
                return temps * 3.154e+12;
            };
            // siècle en microsecondes
            template <typename T>
            T SiecleToMicroSeconde(T temps){
                return temps *  3.154e+15;
            };
            // siècle en nanoseconde
            template <typename T>
            T SiecleToNanoSeconde(T temps){
                return temps *  3.154e+18;
            };
            // ----------------------------------- A ajouter à la doc ----------------------------------
            // décennie en siècle 
            template <typename T>
            T DecennieToSiecle(T temps){
                return temps / 10;
            };
            // décennie en année
            template <typename T>
            T DecennieToAnnee(T temps){
                return temps * 10;
            };
            // décennie en mois
            template <typename T> 
            T DecennieToMois(T temps){
                return temps * 120;
            };
            // décennie en semmaine
            template <typename T>
            T DecennieToSemaine(T temps){
                return temps * 521.4;
            };
            // décennie en jour 
            template <typename T>
            T DecennieToJour(T temps){
                return temps * 3650;
            };
            // décennie en heur
            template <typename T> 
            T DecennieToHeure(T temps){
                return temps * 87600;
            };
            // décennie en minutes 
            template <typename T>
            T DecennieToMinute(T temps){
                return temps * 5.256e+6;
            };
            // décennie en secondes
            template <typename T>
            T DecennieToSeconde(T temps){
                return temps * 3.154e+8;
            };
            // décennie en millisecondes
            template <typename T>
            T DecennieToMilliSeconde(T temps){
                return temps * 3.154e+11;
            };

            // décennie en microsecondes
            template <typename T>
            T DecennieToMicroSeconde(T temps){
                return temps * 3.154e+14;
            };

            // décennie en nanosecondes
            template <typename T> 
            T DecennieToNanoSeconde(T temps){
                return temps * 3.154e+17;
            };

            // année en siècle 
            template <typename T>
            T AnneeToSiecle(T temps){
                return temps / 100;
            };

            // année en décennie 
            template <typename T>
            T AnneeToDecennie(T temps){
                return temps / 10;
            };
            // année en mois 
            template <typename T>
            T AnneeToMois(T temps){
                return temps * 12;
            };
            // année en semmaine 
            template <typename T>
            T AnneeToSemaine(T temps){
                return temps * 52.143;
            };
            // année en jour 
            template <typename T>
            T AnneeToJour(T temps){
                return temps * 365;
            };
            // année en heure
            template <typename T> 
            T AnneeToHeure(T temps){
                return temps * 8760;
            }; 
            // année en minutes
            template <typename T>
            T AnneeToMinute(T temps){
                return temps * 525600;
            };
            // année en secondes
            template <typename T>
            T AnneeToSeconde(T temps){
                return temps * 3.154e+7;
            };
            // année en millisecondes
            template <typename T>
            T AnneeToMilliSeconde(T temps){
                return temps * 3.154e+10;
            };
            // année en Microsecondes
            template <typename T>
            T AnneeToMicroSeconde(T temps){
                return temps * 3.154e+13;
            };
            // année en Nanosecondes
            template <typename T>
            T AnneeToNanoSeconde(T temps){
                return temps * 3.154e+16;
            };
            // mois en siècle
            template <typename T>
            T MoisToSiecle(T temps){
                return temps / 1200;
            };
            // mois en décennie 
            template <typename T>
            T MoisToDecennie(T temps){
                return temps / 120;
            };
            // mois en année
            template <typename T>
            T MoisToAnnee(T temps){
                return temps / 12;
            };
            // mois en semaines
            template <typename T>
            T MoisToSemaine(T temps){
                return temps * 4.345;
            };
            // mois en jour 
            template <typename T>
            T MoisToJour(T temps){
                return temps * 30.417;
            };
            // mois en heur 
            template <typename T>
            T MoisToHeure(T temps){
                return temps * 730;
            };
            // mois en minutes 
            template <typename T>
            T MoisToMinute(T temps){
                return temps * 43800;
            };
            // mois en seconde 
            template <typename T>
            T MoisToSeconde(T temps){
                return temps * 2.628e+6;
            };
            // mois en milliseconde 
            template <typename T>
            T MoisToMilliSeconde(T temps){
                return temps * 2.628e+9;
            };
            //mois en microseconde 
            template <typename T>
            T MoisToMicroSeconde(T temps){
                return temps * 2.628e+12;
            };
            //mois en nanosecondes 
            template <typename T>
            T MoisToNanoSeconde(T temps){
                return temps * 2.628e+15;
            };
            // semaines en siècle 
            template <typename T>
            T SemaineToSiecle(T temps){
                return temps / 5214;
            };
            // semaines en décennie
            template <typename T> 
            T SemaineToDecennie(T temps){
                return temps / 521.4;
            };
            // semaines en année
            template <typename T>
            T SemaineToAnnee(T temps){
                return temps / 52.143;
            };
            // semaines en mois 
            template <typename T>
            T SemaineToMois(T temps){
                return temps / 4.345;
            };
            // semaines en jour 
            template <typename T>
            T SemaineToJour(T temps){
                return temps * 7;
            };
            //semaines en heur 
            template <typename T>
            T SemaineToHeure(T temps){
                return temps * 168;
            };
            //semaines en minute
            template <typename T>
            T SemaineToMinute(T temps){
                return temps * 10080;
            };
            // semaines en secondes 
            template <typename T>
            T SemaineToSeconde(T temps){
                return temps * 604800;
            };
            // semaines en milliseconde
            template <typename T>
            T SemaineToMilliSeconde(T temps){
                return temps * 6.048e+8;
            };
            //semaines en microseconde
            template <typename T>
            T SemaineToMicroSeconde(T temps){
                return temps * 6.048e+11;
            };
            //semaines en nanoseconde
            template <typename T>
            T SemaineToNanoSeconde(T temps){
                return temps * 6.048e+14;
            };
            // jour en siècle 
            template <typename T>
            T JourToSciecle(T temps){
                return temps / 36500;
            };
            // jour en décennie
            template <typename T> 
            T JourToDecennie(T temps){
                return temps / 3650;
            };
            //jour en Année
            template <typename T>
            T JourToAnnee(T temps){
                return temps / 365;
            };
            // jour en mois 
            template <typename T>
            T JourToMois(T temps){
                return temps / 30.417;
            };
            // jour en semaines 
            template <typename T>
            T JourToSemaine(T temps){
                return temps / 7;
            };
            //jour en heure
            template <typename T>
            T JourToHeure(T temps){
                return temps * 24;
            };
            //jour en minutes 
            template <typename T>
            T JourToMinute(T temps){
                return temps * 1440;
            };
            // jour en secondes
            template <typename T>
            T JourToSeconde(T temps){
                return temps * 86400;
            };
            //jour en milliseconde
            template <typename T>
            T JourToMilliSeconde(T temps){
                return temps * 8.64e+7;
            };
            //jour en microseconde
            template <typename T>
            T JourToMicroSeconde(T temps){
                return temps * 8.64e+10;
            };
            //jour en nanoseconde
            template <typename T>
            T JourToNanoSeconde(T temps){
                return temps * 8.64e+13;
            };
            // heure en Siècle 
            template <typename T>
            T HeureToSciecle(T temps){
                return temps / 876000;
            };
            // heure en Décennie 
            template <typename T>
            T HeureToDecennie(T temps){
                return temps / 87600;
            };
            // heure en année 
            template <typename T>
            T HeureToAnnee(T temps){
                return temps / 8760;
            };
            // heure en mois 
            template <typename T>
            T HeureToMois(T temps){
                return temps / 730;
            };
            // heure en semaine 
            template <typename T>
            T HeureToSemaine(T temps){
                return temps / 168;
            };
            // heure en jour 
            template <typename T>
            T HeureToJour(T temps){
                return temps / 24;
            };
            //heure en minute
            template <typename T>
            T HeureToMinute(T temps){
                return temps * 60;
            };
            // heure en seconde 
            template <typename T>
            T HeureToSeconde(T temps){
                return temps * 3600;
            };
            // heure milliseconde
            template <typename T>
            T HeureToMilliSeconde(T temps){
                return temps * 3.6e+6;
            };
            // heure en microseconde 
            template <typename T>
            T HeureToMicroSeconde(T temps){
                return temps * 3.6e+9;
            };
            // heure en nanoseconde
            template <typename T>
            T HeureToNanoSeconde(T temps){
                return temps * 3.6e+12;
            };
            // minute en siècle 
            template <typename T>
            T MinuteToSciecle(T temps){
                return temps / 5.256e+7;
            };
            // minute en décennie 
            template <typename T>
            T MinuteToDecennie(T temps){
                return temps / 5.256e+6;
            };

            //minute en année
            template <typename T>
            T MinuteToAnnee(T temps){
                return temps / 525600;
            };
            // minute en mois 
            template <typename T>
            T MinuteToMois(T temps){
                return temps / 43800;
            };
            //minute en semaine
            template <typename T>
            T MinuteToSemaine(T temps){
                return temps / 10080;
            };
            //minute en jour 
            template <typename T>
            T MinuteToJour(T temps){
                return temps / 1440;
            };
            //minute en heur 
            template <typename T>
            T MinuteToHeure(T temps){
                return temps / 60;
            };
            //minute en seconde
            template <typename T>
            T MinuteToSeconde(T temps){
                return temps * 60;
            };
            //minute en milliseconde
            template <typename T>
            T MinuteToMilliSeconde(T temps){
                return temps * 60000;
            };
            // minute en microseconde
            template <typename T>
            T MinuteToMicroSeconde(T temps){
                return temps * 6e+7;
            };
            // minute en nanoseconde
            template <typename T>
            T MinuteToNanoSeconde(T temps){
                return temps * 6e+10;
            };
            // seconde en siècle 
            template <typename T>
            T SecondeToSiecle(T temps){
                return temps / 3.154e+9;
            };
            // seconde en décennie 
            template <typename T>
            T SecondeToDecennie(T temps){
                return temps / 3.154e+8;
            };
            //seconde en année
            template <typename T>
            T SecondeToAnnee(T temps){
                return temps / 3.154e+7;
            };
            //seconde en mois 
            template <typename T>
            T SecondeToMois(T temps){
                return temps / 2.628e+6;
            };
            // seconde en semaine 
            template <typename T>
            T SecondeToSemaine(T temps){
                return temps / 604800;
            };
            // seconde en jour 
            template <typename T>
            T SecondeToJour(T temps){
                return temps / 86400;
            };
            // seconde en heur 
            template <typename T>
            T SecondeToHeure(T temps){
                return temps / 3600;
            };
            //seconde en minute
            template <typename T>
            T SecondeToMinute(T temps){
                return temps / 60;
            };
            //seconde en milliseconde 
            template <typename T>
            T SecondeToMilliSeconde(T temps){
                return temps * 1000;
            };
            //seconde en microseconde
            template <typename T>
            T SecondeToMicroSeconde(T temps){
                return temps * 1e+6;
            };
            // seconde en nanoseconde 
            template <typename T>
            T SecondeToNanoSeconde(T temps){
                return temps * 1e+9;
            };
            // milliseconde en siècle 
            template <typename T>
            T MilliSecondeToSciecle(T temps){
                return temps / 3.154e+12;
            };
            // milliseconde en décennie 
            template <typename T>
            T MilliSecondeToDecennie(T temps){
                return temps / 3.154e+11;
            };
            // milliseconde en année
            template <typename T>
            T MilliSecondeToAnnee(T temps){
                return temps / 3.154e+10;
            };
            // milliseconde en mois 
            template <typename T>
            T MilliSecondeToMois(T temps){
                return temps / 2.628e+9;
            };
            // milliseconde en semaine
            template <typename T>
            T MilliSecondeToSemaine(T temps){
                return temps / 6.048e+8;
            };
            // milliseconde en jour 
            template <typename T>
            T MilliSecondeToJour(T temps){
                return temps / 8.64e+7;
            };
            // milliseconde en heure
            template <typename T>
            T MilliSecondeToHeure(T temps){
                return temps / 3.6e+6;
            };

            // milliseconde en minute
            template <typename T>
            T MilliSecondeToMinute(T temps){
                return temps / 60000;
            };
            // milliseconde en seconde 
            template <typename T>
            T MilliSecondeToSeconde(T temps){
                return temps / 1000;
            };
            // milliseconde en microseconde
            template <typename T>
            T MilliSecondeToMicroSeconde(T temps){
                return temps * 1000;
            };
            // milliseconde en nanoseconde 
            template <typename T>
            T MilliSecondeToNanoSeconde(T temps){
                return temps * 1e+6;
            };
            // microseconde en siècle 
            template <typename T>
            T MicroSecondeToSiecle(T temps){
                return temps / 3.154e+15;
            };
            // microseconde en décennie 
            template <typename T>
            T MicroSecondeToDecennie(T temps){
                return temps / 3.154e+14;
            };
            // microseconde en année 
            template <typename T>
            T MicroSecondeToAnnee(T temps){
                return temps / 3.154e+13;
            };
            // microseconde en mois 
            template <typename T>
            T MicroSecondeToMois(T temps){
                return temps / 2.628e+12;
            };
            // microseconde en semaine
            template <typename T>
            T MicroSecondeToSemaine(T temps){
                return temps / 6.048e+11;
            };
            // microseconde en jour 
            template <typename T>
            T MicroSecondeToJour(T temps){
                return temps / 8.64e+10;
            };
            // microseconde en heure
            template <typename T>
            T MicroSecondeToHeure(T temps){
                return temps / 3.6e+9;
            };
            //microseconde en minute
            template <typename T>
            T MicroSecondeToMinute(T temps){
                return temps / 6e+7;
            };
            // microseconde en seconde
            template <typename T>
            T MicroSecondeToSeconde(T temps){
                return temps / 1e+6;
            };
            // microseconde en milliseconde 
            template <typename T>
            T MicroSecondeToMilliSeconde(T temps){
                return temps / 1000;
            };
            // microseconde en nanoseconde 
            template <typename T>
            T MicroSecondeToNanoSeconde(T temps){
                return temps * 1000;
            };
            // nanoseconde en siècle 
            template <typename T>
            T NanoSecondeToSciecle(T temps){
                return temps / 3.154e+18;
            };

            // nanoseconde en décennie 
            template <typename T>
            T NanoSecondeToDecennie(T temps){
                return temps / 3.154e+17;
            };
            // nanoseconde en Année
            template <typename T>
            T NanoSecondeToAnnee(T temps){
                return temps / 3.154e+16;
            };
            // nanoseconde en Mois
            template <typename T> 
            T NanoSecondeToMois(T temps){
                return temps / 2.628e+15;
            };
            // nanoseconde en Semaine
            template <typename T>
            T NanoSecondeToSemaine(T temps){
                return temps / 6.048e+14;
            };
            // nanoseconde en jour 
            template <typename T>
            T NanoSecondeToJour(T temps){
                return temps / 8.64e+13;
            };
            // nanoseconde en heure
            template <typename T>
            T NanoSecondeToHeure(T temps){
                return temps / 3.6e+12;
            };
            // nanoseconde en minute 
            template <typename T>
            T NanoSecondeToMinute(T temps){
                return temps / 6e+10;
            };
            // nanoseconde en seconde
            template <typename T>
            T NanoSecondeToSeconde(T temps){
                return temps / 1e+9;
            };
            // nanoseconde en milliseconde
            template <typename T>
            T NanoSecondeToMilliSeconde(T temps){
                return temps / 1e+6;
            };
            // nanoseconde en microseconde 
            template <typename T>
            T NanoSecondeToMicroSeconde(T temps){
                return temps / 1000;
            };
        };
        // ------------------------------------------- continuer à partit d'ici
        
        namespace Frequence{
            
            // Hertz en KiloHertz
            template <typename T>
            T HertzToKiloHertz(T Hertz){
                return Hertz / 1000;
            };
            // Hertz en MegaHertz
            template <typename T>
            T HertzToMegaHertz(T Hertz){
                return Hertz / 1e+6;
            };
            // Hertz en GigaHertz
            template <typename T>
            T HertzToGigaHertz(T Hertz){
                return Hertz / 1e+9;
            };

            // KiloHertz en Hertz
            template <typename T>
            T KiloHertzToHertz(T KiloHertz){
                return KiloHertz * 1000;
            };
            // KiloHertz en MegT
            template <typename T>
            T KiloHertzToMegaHertz(T KiloHertz){
                return KiloHertz / 1000;
            };
            // KiloHertz en GigaHertz
            template <typename T>
            T KiloHertzToGigaHertz(T KiloHertz){
                return KiloHertz / 1e+6;
            };

            // MegaHertz en Hertz
            template <typename T>
            T MegaHertzToHertz(T MegaHertz){
                return MegaHertz * 1e+6;
            };

            // MegaHertz en KiloHertz
            template <typename T>
            T MegaHertzToKiloHertz(T MegaHertz){
                return MegaHertz * 1000;
            };
            // MegaHertz en GigaHertz
            template <typename T>
            T MegaHertzToGigaHertz(T MegaHertz){
                return MegaHertz / 1000;
            };


            // GigaHertz en Hertz
            template <typename T>
            T GigaHertzToHertz(T GigaHertz){
                return GigaHertz * 1e+9;
            };
            // GigaHertz en KiloHertz
            template <typename T>
            T GigaHertzToKiloHertz(T GigaHertz){
                return GigaHertz * 1e+6;
            };
            // GigaHertz en MegaHertz
            template <typename T>
            T GigaHertzToMegaHertz(T GigaHertz){
                return GigaHertz * 1000;
            };

        };

        // à ajouter à la documentation 
        namespace Masse{
            
            // Tonne en Kilogramme
            template <typename T>
            T TonneToKilogramme(T Tonne){
                return Tonne * 1000;
            };

            // Tonne en Gramme
            template <typename T>
            T TonneToGramme(T Tonne){
                return Tonne * 1e+6;
            };

            // Tonne en MiliGramme
            template <typename T>
            T TonneToMiliGramme(T Tonne){
                return Tonne * 1e+9;
            };

            // Tonne en MicroGramme
            template <typename T>
            T TonneToMicroGramme(T Tonne){
                return Tonne * 1e+12;
            };

            // Tonne en TonneLongue
            template <typename T>
            T TonneToTonneLongue(T Tonne){
                return Tonne / 1.016;
            };

            // Tonne en TonneCourte
            template <typename T>
            T TonneToTonneCourte(T Tonne){
                return Tonne * 1.102;
            };

            // Tonne en Stone
            template <typename T>
            T TonneToStone(T Tonne){
                return Tonne * 157.5;
            };

            // Tonne en Livre
            template <typename T>
            T TonneToLivre(T Tonne){
                return Tonne * 2205;
            };
            
            // Tonne en Once
            template <typename T>
            T TonneToOnce(T Tonne){
                return Tonne * 35270;
            };

            // KiloGramme en Tonne
            template <typename T>
            T KiloGrammeToTonne(T KiloGramme){
                return KiloGramme / 1000;
            };

            // KiloGramme en Gramme
            template <typename T>
            T KiloGrammeToGramme(T KiloGramme){
                return KiloGramme * 1000;
            };

            // KiloGramme en MilliGramme
            template <typename T>
            T KiloGrammeToMilliGramme(T KiloGramme){
                return KiloGramme * 1e+6;
            };

            // KiloGramme en Microgramme
            template <typename T>
            T KiloGrammeToMicroGramme(T KiloGramme){
                return KiloGramme * 1e+9;
            };

            // KiloGramme en TonneLongue
            template <typename T>
            T KiloGrammeTonneLongue(T KiloGramme){
                return KiloGramme / 1016;
            };

            // KiloGramme en TonneCourte
            template <typename T>
            T KiloGrammeTonneCourte(T KiloGramme){
                return KiloGramme / 907.2;
            };

            // KiloGramme en Stone 
            template <typename T>
            T KiloGrammeStone(T KiloGramme){
                return KiloGramme / 6.35;
            };

            // KiloGramme en Livre 
            template <typename T>
            T KiloGrammeLivre(T KiloGramme){
                return KiloGramme * 2.205;
            };

            // KiloGramme en Once
            template <typename T>
            T KiloGrammeOnce(T KiloGramme){
                return KiloGramme * 35.274;
            };


            // Gramme en Tonne
            template <typename T>
            T GrammeTonne(T Gramme){
                return Gramme / 1e+6;
            };



            // à continuer 
            // ses les masse

        
            
           // https://www.google.com/search?q=conversion+km+en+cm&sca_esv=54037a4a3ceac2e9&rlz=1C1CHZN_frFR1086FR1086&sxsrf=ADLYWIKGhYAtBtKrugmSXSAq4Zh9jytL0A%3A1728764731022&ei=O9sKZ9Fy3auR1Q_48oeICw&ved=0ahUKEwiR_MS91omJAxXdVaQEHXj5AbEQ4dUDCA8&uact=5&oq=conversion+km+en+cm&gs_lp=Egxnd3Mtd2l6LXNlcnAiE2NvbnZlcnNpb24ga20gZW4gY20yBRAAGIAEMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yCBAAGBYYHhgPMgYQABgWGB5IsSFQuAlYqxtwAXgBkAEAmAFOoAH0BKoBATm4AQPIAQD4AQGYAgqgAt8FwgIKEAAYsAMY1gQYR8ICChAjGIAEGCcYigXCAgoQABiABBhDGIoFwgIIEAAYgAQYsQPCAgoQABiABBgUGIcCmAMAiAYBkAYIkgcCMTCgB8U0&sclient=gws-wiz-serp
            


            

        };

        
        
    };

};