#include "mouse.h"
#include <stdbool.h>

bool isThatInHand(SDL_Event event, int *no, HandList *hand, int *index){
    int ii;
    bool isThere = false;
    int x = event.button.x;
    int y = event.button.y;
    int currX, currY;
    HandItem *temp;

    for(ii = 0; ii < 7;ii++){
        currX = posOfHands[ii].x;
        currY = posOfHands[ii].y;
        if(x >= currX && x <= currX + 65 && y >= currY && y <= currY + 65){
            *index = ii;
            isThere = true;
        }
    }
    if(isThere){
        for(temp = hand->first;temp != NULL;temp = temp->next){
            if(temp->index == *index){
                *no = temp->no;
            }
        }
    }

    return isThere;
}

bool isOnTable(SDL_Event event, HandList *hand, int index, int *drawX, int *drawY){
    bool isThere = false;
    int ii,jj;
    int x = event.button.x;
    int y = event.button.y;
    int currX, currY;
    HandItem *temp = hand->first;
    for(;temp->index != index;temp = temp->next ){
        ii = 0;
    }
    if(x >= 1 && x <= 825 && y >= 1 && y <= 825){
        for(ii=0;ii<15;ii++){
            for(jj=0;jj<15;jj++){
                currX = board[ii][jj].x;
                currY = board[ii][jj].y;
                if(x > currX && x < currX + 58 && y > currY && y < currY + 58 && board[ii][jj].Stone == -1){
                    //SDL_Log("sqf");
                    delHandItem(hand->first, index, hand);
                    *drawX = currX;
                    *drawY = currY;
                    board[ii][jj].Stone = temp->no;
                    //SDL_Log("%d", temp->no);
                    isThere = true;
                }
            }
        }
    }

    return isThere;
}

/*bool isOnResetButton(SDL_Event event, t_button *reset){
    if(event.motion.x >= reset->x + 300 && event.motion.x <= reset->x
       && event.motion.y >= reset->y + 50 && event.motion.y <= reset->y){
        reset->hover = true;
       }else reset->hover = false;
    return reset->hover;
}*/
