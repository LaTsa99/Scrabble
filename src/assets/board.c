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
    SDL_Rect dest = {0,0,825,825};

    x = SDL_RenderCopy(r,board,&source,&dest);
    if(x < 0){
        SDL_Log("Couldn't copy texture: %s", SDL_GetError());
        exit(1);
    }
}

void defineBoard(){
    int ii,jj;
    for(ii=0;ii<15;ii++){
        for(jj=0;jj<15;jj++){
            board[ii][jj].x = 3 + ii*55;
            board[ii][jj].y = 4 + jj*55;
        }
    }
}
