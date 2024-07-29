#include <iostream>
#include <SDL2/SDL.h>
#include "../../Tina_TOOLS/Tina_TOOLS_sdl_forme.hpp"

int WinMain(){
    Tina_TOOLS_sdl_forme tin_f;

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "Erreur d'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    // creation de la fenetre 640 et 480
    SDL_Window* window = SDL_CreateWindow("Ma fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 940, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window){
        std::cerr << "Erreur de création de la fenêtre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // creation du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer){
        std::cerr << "Erreur de creation du renderer : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool quit = false;


    // Boucle principale
    while (!quit){
        while (SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }

        // int x = 20, int y =  20, int w = 900, int h = 440
        tin_f.Tina_SDL_DRAW_RECTANGLE_1(20, 20, 900, 440, renderer, 255, 0, 0, 255);

        SDL_RenderPresent(renderer);
    }

    // nettoyage des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
