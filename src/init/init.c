#include "init.h"
#include <SDL.h>

void Game_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer,char* lang){
    //Spielsteinen erstellen
    if(lang != NULL){
        generateStones(lang);
        if(Stones == NULL){
            SDL_Log("Couldn't create stones: %s", SDL_GetError);
            exit(1);
        }
    }
    //Initialisieren von SDL Bibliotheken
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        exit(1);
    }
    //Window erstellen
    SDL_Window *window = SDL_CreateWindow("Scrabble v1.0", 200, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == NULL){
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        exit(1);
    }
    //Renderer ersetellen
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL){
        SDL_Log("Couldn't create renderer: %s", SDL_GetError());
        exit(1);
    }

    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}

void Control_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer){
    //Window erstellen
    SDL_Window *window = SDL_CreateWindow("Scrabble v1.0", 1000, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == NULL){
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        exit(1);
    }
    //Renderer ersetellen
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL){
        SDL_Log("Couldn't create renderer: %s", SDL_GetError());
        exit(1);
    }

    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}
