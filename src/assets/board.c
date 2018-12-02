#include "board.h"

//draws the board on the screen
void generateBoard(SDL_Renderer *r, char* src){
    int width = 0, height = 0, x;
    //imports the texture from the file
    //original: https://www.flickr.com/photos/xouved/5371523488
    SDL_Texture *board = IMG_LoadTexture(r,src);
    if(board == NULL){
        SDL_Log("Board: Couldn't load board: %s",SDL_GetError());
        exit(1);
    }
    //gets all kind of data about the texture (width, height, ...)
    SDL_QueryTexture(board, NULL, NULL, &width, &height);
    if(width == 0 || height == 0){
        SDL_Log("Board: Couldn't query texture: %s",SDL_GetError());
        exit(1);
    }

    //sends the texture to the renderer
    SDL_Rect source = {NULL, NULL, width, height};
    SDL_Rect dest = {0,0,873,873};

    x = SDL_RenderCopy(r,board,&source,&dest);
    if(x < 0){
        SDL_Log("Board: Couldn't copy texture: %s", SDL_GetError());
        exit(1);
    }
    //frees texture from the memory
    SDL_DestroyTexture(board);
}

//sets the initial state of the board and reset matrices
void defineBoard(t_board board[15][15], previous_step *rst){
    int ii,jj;

    for(ii=0;ii<15;ii++){
        for(jj=0;jj<15;jj++){
            board[ii][jj].x = 3+ii*58;
            board[ii][jj].y = 4+jj*58;
            board[ii][jj].Stone = -1;
        }
    }
    for(ii=0;ii<7;ii++){
        rst[ii].ii = -1;
        rst[ii].jj = -1;
    }
}
