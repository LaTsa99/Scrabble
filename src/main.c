#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
//#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "init/init.h"
//#include "assets/button.h"
#include "assets/board.h"
#include "assets/stone_img.h"
#include "assets/hand.h"
#include "game/mouse.h"
#include "game/render.h"
#include "game/events.h"


int main(int argc, char *argv[]) {
    int width = 1467;
    int height = 873;
    int no, index;
    int x, y;
    bool holdingStone = false;
    bool quit = false;
    //bool center = false;
    int centerError = 0;
    int valid = 1;
    TTF_Font *font;
    HandList *hand;
    SDL_Window *window;
    SDL_Renderer *renderer;
    //t_button ResetButton ={"Reset", false, false, 1000, 500};

    hand = (HandList*)malloc(sizeof(HandList));

    srand(time(NULL));



    Game_init(width,height,&window,&renderer, hand, &font);
    refreshRenderer(renderer, font, hand, centerError, valid);
    //SDL_Log("2");
    SDL_RenderPresent(renderer);
    SDL_Event event;

    while(!quit){
        SDL_WaitEvent(&event);
        switch(event.type){
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if(event.button.button == SDL_BUTTON_LEFT){
                if(isThatInHand(event, &no, hand, &index)){
                    holdingStone = true;
                }else if(holdingStone && isOnTable(event, hand, index, &x, &y)){
                    holdingStone = false;
                }
            }
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_f)
                enterWord(hand, &centerError, &valid);
            else if(event.key.keysym.sym == SDLK_r){
                resetState(hand);
                holdingStone = false;
            }
            else if(event.key.keysym.sym == SDLK_g)
                mixLetters(hand, &centerError, &valid);
            else if(event.key.keysym.sym == SDLK_ESCAPE)
                quit = true;
        }
        SDL_RenderClear(renderer);
        refreshRenderer(renderer, font, hand, centerError, valid);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(Stones);
    freeHand(hand->first);
    free(hand);
    TTF_CloseFont(font);
    SDL_Quit();

    return 0;
}
