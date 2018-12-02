#include <SDL2/SDL.h>
#include <SDL_image.h>

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "init/init.h"
#include "assets/board.h"
#include "assets/stone_img.h"
#include "assets/hand.h"
#include "game/mouse.h"
#include "game/render.h"
#include "game/events.h"



int main(int argc, char *argv[]) {
    int width = 1467;
    int height = 873;
    int x, y;

    int no, index;
    int score = 0;
    char score_str[5] = "0";
    bool holdingStone = false;
    bool quit = false;

    eventTable events = {0,1,1,0,0,0,98};

    t_Stones Stones[100];
    t_board board[15][15];
    previous_step rst[7];
    int RandTable[100];
    HandPosition posOfHands[7];
    int prev[7];


    TTF_Font *font;
    HandList *hand;
    SDL_Window *window;
    SDL_Renderer *renderer;

    hand = (HandList*)malloc(sizeof(HandList));

    srand(time(NULL));


    Game_init(width,height,&window,&renderer, hand, &font, board, Stones, rst, RandTable, posOfHands, prev);
    refreshRenderer(renderer, font, hand, board, score_str, Stones, &events, posOfHands);
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
                if(isThatInHand(event, &no, hand, &index, posOfHands)){
                    holdingStone = true;
                }else if(holdingStone && isOnTable(event, hand, index, &x, &y,board, Stones, &events, rst)){
                    holdingStone = false;
                }
            }
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_f)
                enterWord(hand, board, &score, score_str, Stones, rst, &events, RandTable, prev);
            else if(event.key.keysym.sym == SDLK_r){
                resetState(hand, board, &(events.connected), Stones, rst, RandTable, prev);
                holdingStone = false;
            }
            else if(event.key.keysym.sym == SDLK_g)
                mixLetters(hand, board, &score, score_str, Stones, rst, &events, RandTable, prev);
            else if(event.key.keysym.sym == SDLK_h)
                changeTile(hand,RandTable,prev,index);
            else if(event.key.keysym.sym == SDLK_ESCAPE)
                quit = true;
        }
        SDL_RenderClear(renderer);
        refreshRenderer(renderer, font, hand, board, score_str, Stones, &events, posOfHands);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    freeHand(hand->first);
    free(hand);
    TTF_CloseFont(font);
    SDL_Quit();

    return 0;
}
