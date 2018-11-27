#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "init/init.h"
#include "assets/button.h"
#include "assets/board.h"
#include "assets/stone_img.h"


int main(int argc, char *argv[]) {
    char lang[3] = "de";
    int width = 1467;
    int height = 825;
    bool quit = false;
    char src[] = "Scrabbleboard.jpg";
    char stn[] = "stones_texture_de.png";

    SDL_Window *window;
    SDL_Renderer *renderer;

    Game_init(width,height,&window,&renderer,lang);
    generateBoard(renderer,src);
    drawStone(renderer,stn, 55,3,3);
    drawStone(renderer,stn, 97,57,3);
    #if DEBUG == 1
    for(int ii=0;ii<102;ii++){
        printf("%c, %d, %d, %d\n", Stones[ii].name, Stones[ii].pts, Stones[ii].x, Stones[ii].y);
    }
    #endif

    SDL_RenderPresent(renderer);
    SDL_Event event;

    while(!quit){
        SDL_WaitEvent(&event);
        switch(event.type){
        case SDL_QUIT:
            SDL_Quit();
        }
    }

    return 0;
}
