#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "import/stones.h"

char board[15][15];

int main(int argc, char *argv[]) {
    char lang[3] = "de";
    SDL_Window *window1;
    SDL_Window *window2;
    SDL_Renderer *renderer1;
    SDL_Renderer *renderer2;
    Game_init(800,800,&window1,&renderer1,lang);
    Control_init(800,800,&window2,&renderer2);

    SDL_Texture *scrabble_de = IMG_LoadTexture(renderer1, "Scrabbleboard.jpg");
    if(scrabble_de == NULL){
        SDL_Log("Couldn't import german scrabbleboard: %s", SDL_GetError());
        exit(1);
    }


    SDL_RenderCopy(renderer1,scrabble_de,NULL,NULL);

    SDL_RenderPresent(renderer1);
    SDL_RenderPresent(renderer2);

    bool quit = false;
    while(!quit){
        SDL_Event event;
        SDL_WaitEvent(&event);

        switch(event.type){
        case SDL_KEYDOWN:
            quit = true;
            break;
        case SDL_QUIT:
            quit = true;
            break;
        }
    }

    /*SDL_DestroyTexture(menu_bckg);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);*/

    return 0;
}
