/**
 * @file Tina_TOOLS_sdl_forme.hpp
 * @brief Cette class permet de gérez la creation de formes pour la librairie sdl  
 * 
 * @note Vous pouvez compiler votre programme avec la ligne de commande ci-dessous si vous utiliser cette classe.
 * 
 * @brief
 * g++ -o example_1.exe example_1.cpp -mwindows -lSDL2
 *  
 * Pour utiliser cette classe, vous devez inclure les bibliothèques suivantes :
 * - librairie fournit de base par le C/C++
 * - SDL2
 * 
 * Fichier .hpp ou h qui et utiliser par la classe :
 * - aucun
 *
 * Disponibilité :
 * - Windows
 * 
 * @note Assurez-vous d'avoir les lib sur vôtre système sinon installer les lib nécessaire.
 * 
 * @author Tina
 * @date 29/07/2024
 * @version 0.2
 * @copyright Copyright 2024 Tina - Tous droits réservés
*/
#ifndef Tina_TOOLS_sdl_forme_
#define Tina_TOOLS_sdl_forme_

#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>


class Tina_TOOLS_sdl_forme{
private:


public:
    /**
     * @fn Tina_SDL_DRAW_RECTANGLE_1()
     * @param [int x] attend un entier qui définis l'abscisse 
     * @param [int y] attend un entier qui définis l'ordoner
     * @param [int w] attend un entier qui définis width 
     * @param [int h] attend un entier qui définis height
     * @param [SDL_Renderer* renderer] attend le rendu
     * @param [Uint8 rgb_r] attend un entier qui définis le paramètre r de la function rgb
     * @param [Uint8 rgb_g] attend un entier qui définis le paramètre g de la function rgb
     * @param [Uint8 rgb_b] attend un entier qui définis le paramètre b de la function rgb
     * @param [Uint8 rgb_a] attend un entier qui définis le paramètre a de la function rgb de la sdl il et a 255 généralement
     * @note Cette fonction permet de dessiner que la bordure d'un rectangle en couleur pas l'interrieur
     * 
     * Example d'utilisation : 
     * @warning l'example de cette function et dans le dossier example_sdl et ces le fichier example_1.cpp
    */
    static void Tina_SDL_DRAW_RECTANGLE_1(int x,int y,int w,int h,SDL_Renderer* renderer,Uint8 rgb_r,Uint8 rgb_g,Uint8 rgb_b,Uint8 rgb_a){
        SDL_Rect fillRect = {x, y, w, h};
        SDL_SetRenderDrawColor(renderer, rgb_r, rgb_g, rgb_b, rgb_a);
        SDL_RenderDrawRect(renderer, &fillRect);
        SDL_RenderPresent(renderer);
    }

    /**
     * @fn Tina_SDL_DRAW_RECTANGLE_2()
     * @param [int x] attend un entier qui définis l'abscisse 
     * @param [int y] attend un entier qui définis l'ordoner
     * @param [int w] attend un entier qui définis width 
     * @param [int h] attend un entier qui définis height
     * @param [SDL_Renderer* renderer] attend le rendu
     * @param [Uint8 rgb_r] attend un entier qui définis le paramètre r de la function rgb
     * @param [Uint8 rgb_g] attend un entier qui définis le paramètre g de la function rgb
     * @param [Uint8 rgb_b] attend un entier qui définis le paramètre b de la function rgb
     * @param [Uint8 rgb_a] attend un entier qui définis le paramètre a de la function rgb de la sdl il et a 255 généralement
     * @note Cette fonction permet de dessiner la bordure et le contenu d'un rectangle de la même couleur
     * 
     * 
     * Example d'utilisation : 
     * @warning l'example de cette function et dans le dossier example_sdl et ces le fichier example_2.cpp
    */
    static void Tina_SDL_DRAW_RECTANGLE_2(int x,int y,int w,int h,SDL_Renderer* renderer,Uint8 rgb_r,Uint8 rgb_g,Uint8 rgb_b,Uint8 rgb_a){
        SDL_Rect fillRect = {x, y, w, h};
        SDL_SetRenderDrawColor(renderer, rgb_r, rgb_g, rgb_b, rgb_a);
        SDL_RenderFillRect(renderer, &fillRect);
        SDL_RenderPresent(renderer);
    }


};

/*
Compilation : 
g++ -o example_1.exe example_1.cpp -mwindows -lSDL2
*/

#endif