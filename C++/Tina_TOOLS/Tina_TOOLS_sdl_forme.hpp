#ifndef Tina_TOOLS_sdl_forme_
#define Tina_TOOLS_sdl_forme_

#include <SDL2/SDL.h> // abandon de la SDL2 quand la SDL3 cera stable je la telechargerais et passerais la version du code sous la 
//sdl3
#include <iostream>
#include <math.h>


class Tina_TOOLS_sdl_forme{
private:


public:
    static void Tina_SDL_DRAW_RECTANGLE_1(int x,int y,int w,int h,SDL_Renderer* renderer,Uint8 rgb_r,Uint8 rgb_g,Uint8 rgb_b,Uint8 rgb_a){
        SDL_Rect fillRect = {x, y, w, h};
        SDL_SetRenderDrawColor(renderer, rgb_r, rgb_g, rgb_b, rgb_a);
        SDL_RenderDrawRect(renderer, &fillRect);
        SDL_RenderPresent(renderer);
    }

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