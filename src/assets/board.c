#include "board.h"

void generateBoard(SDL_Renderer *r, char* src){
    int width = 0, height = 0, x;
    SDL_Texture *board = IMG_LoadTexture(r,src);
    if(board == NULL){
        SDL_Log("Couldn't load board: %s",SDL_GetError());
        exit(1);
    }

    SDL_QueryTexture(board, NULL, NULL, &width, &height);
    if(width == 0 || height == 0){
        SDL_Log("Couldn't query texture: %s",SDL_GetError());
        exit(1);
    }

    SDL_Rect source = {NULL, NULL, width, height};
    SDL_Rect dest = {0,0,600,600};

    x = SDL_RenderCopy(r,board,&source,&dest);
    if(x < 0){
        SDL_Log("Couldn't copy texture: %s", SDL_GetError());
        exit(1);
    }
}
