#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "init/init.h"
#include "assets/button.h"
#include "assets/board.h"

int board[15][15];

int main(int argc, char *argv[]) {
    char lang[3] = "de";
    int width = 1280;
    int height = 720;
    bool quit = false;
    char src[] = "Scrabbleboard.jpg";

    SDL_Window *window;
    SDL_Renderer *renderer;

    Game_init(width,height,&window,&renderer,lang);

    /*SDL_Texture *scrabble_de = IMG_LoadTexture(renderer, "Scrabbleboard.jpg");
    if(scrabble_de == NULL){
        SDL_Log("Couldn't import german scrabbleboard: %s", SDL_GetError());
        exit(1);
    }


    SDL_RenderCopy(renderer,scrabble_de,NULL,NULL);*/
    generateBoard(renderer,src);

    SDL_RenderPresent(renderer);

    while(!quit){

    }

    return 0;
}
