#include "mouse.h"
#include <stdbool.h>

//places tile from your hand to your "real hand"
bool isThatInHand(SDL_Event event, int *no, HandList *hand, int *index, HandPosition *posOfHands){
    int ii;
    bool isThere = false;
    int x = event.button.x;
    int y = event.button.y;
    int currX, currY;
    HandItem *temp;

    //checks if the player clicked on a tile in the hand
    for(ii = 0; ii < 7;ii++){
        currX = posOfHands[ii].x;
        currY = posOfHands[ii].y;
        if(x >= currX && x <= currX + 65 && y >= currY && y <= currY + 65){
            *index = ii;
            isThere = true;
        }
    }

    //if the player clicked on a tile, sends the data to main
    if(isThere){
        for(temp = hand->first;temp != NULL;temp = temp->next){
            if(temp->index == *index){
                *no = temp->no;
            }
        }
    }

    return isThere;
}

//checks, if the player clicked on the board
bool isOnTable(SDL_Event event, HandList *hand, int index, int *drawX, int *drawY, t_board board[15][15], t_Stones *Stones, eventTable *events, previous_step *rst){
    bool isThere = false;
    int ii,jj, zz = 0;
    int x = event.button.x;
    int y = event.button.y;
    int currX, currY;
    HandItem *temp = hand->first;

    //search for the selected tile in the hand
    for(;temp->index != index;temp = temp->next ){
        ii = 0;
    }

    //searches the element on the board, where has been clicked
    if(x >= 1 && x <= 873 && y >= 1 && y <= 873){
        for(ii=0;ii<15  && !isThere;ii++){
            for(jj=0;jj<15;jj++){
                currX = board[ii][jj].x;
                currY = board[ii][jj].y;

                //makes sure, that there are no other tiles
                if(x > currX && x < currX + 58 && y > currY && y < currY + 58 && board[ii][jj].Stone == -1){
                    delHandItem(hand->first, index, hand);
                    *drawX = currX;
                    *drawY = currY;
                    board[ii][jj].Stone = temp->no;

                    //searches for the first free element of the reset array, and sets the current move there
                    while(rst[zz].ii != -1){
                        zz++;
                    }
                    rst[zz].ii = ii;
                    rst[zz].jj = jj;
                    isThere = true;

                    //if there are lonely tiles, throws and error on the screen
                    if(events->connected == 0){
                        if(ii > 0){
                            if(board[ii-1][jj].Stone != -1 || board[ii+1][jj].Stone != -1) events->connected = 1;
                        }else{
                            if(board[ii+1][jj].Stone != -1) events->connected = 1;
                        }
                        if(jj > 0){
                            if(board[ii][jj-1].Stone != -1 || board[ii][jj+1].Stone != -1) events->connected = 1;
                        }else{
                            if(board[ii][jj+1].Stone != -1) events->connected = 1;
                        }
                    }


                }
            }
        }
    }

    //checks if the placed tile is a joker
    if(Stones[temp->no].name == 'j'){
        events->jokerInput = 1;
        events->currentJoker = temp->no;
    }

    return isThere;
}
