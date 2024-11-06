#include <iostream>
#include <cmath>
#include "MathTina.hpp"


int main(){


    double result = Mathematique::Convertion::Temps::SiecleToHeur(13);
    std::cout << result << std::endl;

    



    // int resultD = Mathematique::Calcule::DistanceTimeSpeed::Distance(45, 60);
    // std::cout << "Distance : " << resultD  << " Donc 2.7 kilomètre"<< std::endl;

    // int resultT = Mathematique::Calcule::DistanceTimeSpeed::Temps(resultD, 45);
    // std::cout << "Temps : " << resultT << std::endl;

    // int resultV = Mathematique::Calcule::DistanceTimeSpeed::Vitesse(resultD, resultT);
    // std::cout << "Vitesse : " << resultV << std::endl;

       /*
            T A1; V A2;
            U B1; W B2;
        */

    // ça marche car j'ai fait ceci 
    /*
    
    je cre une structur pour faire le produit en croix donc A1, A2, B1, B2,  la fonction renvoi la structure du produit en croix 
    chaque paramètre dans ma structure et un template comme ça je peut avoir des nombre a virgule ou  entier ou autre 

    après dans ma fonction je dis de à l'utilisateur de passer en paramètre ça structure de produit a calculer et un deuxième paramètre 
    qui et l'emplacement de X donc ce deuxième paramètre dans ma fonction on l'utilise comme ça 

    A1 = 1, A2 = 2, B1 = 3, et B2 = 4 

    maintenant que l'on sais ou sont positionner les nombre dans ma structure bas 
    pour placer x dans la structure on met par convention 0 comme ça on sais que ces le x a chercher pour nous pas pour le programm
    on peut très bien mettre un autre nombre 
    
    ducoup le deuxième paramètre de la fonction qui calcule le produit on lui indique ou et x donc dans mon cas il et a B2 donc 
    je met 4 et comme ça ça va calculer 5 x 6 / 3 et si on avait un 0 dans notre produit en croix on nomerais notre x -0 comme ça 
    on ce trompe pas visuellement et ducoup ça calculerais le 0 et ducoup grace a cette methode 
    on peut calculer même le 0 car si on avait dit que 0 représente x bas si il y a un 0 dans notre produit en croix ça aurais 
    pas marcher tandis que si on met un nombre aléatoir a la place de x genre 55 ou 0 ou autre et que l'on indique la position de 
    x bas ça va faire le calcule, ducoup si on a un 0 dans notre produit en croix on peut dire que le x on le met à 66666 et on indique 
    la position example : 
    
    donc ou il y a le 66666 bas ses le x et ducoup il et placer en A1 la position de A1 ses 1 donc 
    en deuxième paramètre dans ma fonction on mettera 1

    Mathematique::Calcule::ProduitInCroix<int, int, int, int> produit1 = {66666,  6, 
                                                                          5,      4};
    
    Mathematique::Calcule::ProduitInCroix<int, int, int, int> result = Mathematique::Calcule::ProduitInCroixCalculat<int, int, int, int, int>(produit1, 1);
    std::cout << result.A1 << std::endl;


    fin de l'example 

    enfaite ce que je veut dire c'est que je met le x juste parce que sinon si je met rien en nombre le compilateur va geuler 
    puis après j'indique la place de x donc si il et à A1, ou A2, ou B1, ou B2 puis ma fonction va vérifier ce que l'on a mis en deuxième 
    paramètre en  fonction de ce que l'on a mis elle fera ça x ça / par cela et on aura plus que a 
    stocker sous la form de la structure notre fonction et on fait le nom de la structur qui stock la fonction . ou et le x donc A1 ou B1 ou autre
    
    */
    //                     type de la structur : A1   A2   B1   B2
    /*Mathematique::StructuresMath::ProduitInCroix<int, int, int, int> produit1 = {3,  6, 
                                                                                 5,  0};
    //               type de la structur :       A1   A2   B1   B2                                             type de  :   A1   A2  B1   B2   type de retour de la fonction                                                                                                           
    Mathematique::StructuresMath::ProduitInCroix<int, int, int, int> result = Mathematique::Calcule::ProduitInCroixCalculat<int, int, int, int, float>(produit1, 4); 
    std::cout << result.B2 << std::endl;*/

    return 0;
}