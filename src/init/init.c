#include "init.h"
#include <SDL.h>

void Game_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer,
               HandList *hand, TTF_Font **font, t_board board[15][15], t_Stones *Stones,
               previous_step *rst, int *RandTable, HandPosition *posOfHands, int *prev){
    //Initializing of SDL libraries
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        exit(1);
    }
    //Create Window
    SDL_Window *window = SDL_CreateWindow("Scrabble v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == NULL){
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        exit(1);
    }
    //Create Renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL){
        SDL_Log("Couldn't create renderer: %s", SDL_GetError());
        exit(1);
    }

    SDL_RenderClear(renderer);

    //initializing most important arrays / matrices
    generateStones(Stones);
    defineBoard(board, rst);

    //initializing font and hand
    initFont(font);
    initialHand(hand, RandTable, posOfHands, prev);

    *pwindow = window;
    *prenderer = renderer;
}
