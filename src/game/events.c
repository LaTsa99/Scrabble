#include "events.h"



void enterWord(HandList *hand, int *centerError, int *valid){
    int ii,jj, zz = 0;
    char line1[16];
    char line2[16];
    bool ok = true;

    line1[15] = line2[15] = '\0';

    if(board[7][7].Stone == -1){
        resetState(hand);
        *centerError = 1;


    }else{
        for(ii = 0;ii < 15; ii++){

            for(jj = 0;jj < 15; jj++){
                if(board[ii][jj].Stone != -1){
                        SDL_Log("%d", board[ii][jj].Stone);
                    line1[jj] = Stones[board[ii][jj].Stone].name;
                   // SDL_Log("%c", line1[ii]);
                }else{
                    line1[jj] = '1';

                }
                if(board[jj][ii].Stone != -1){
                        SDL_Log("%d", board[jj][ii].Stone);
                    line2[jj] = Stones[board[jj][ii].Stone].name;
                   // SDL_Log("%c", line2[ii]);
                }else{
                    line2[jj] = '1';
                }

                //SDL_Log("%c", line2[ii]);

            }
            if(!checkWord(line1) || !checkWord(line2)) ok = false;
        }
    }
    if(ok){
        *valid = 1;
        for(;zz<7;zz++){
            rst[zz].ii = -1;
            rst[zz].jj = -1;
        }
        if(hand->first == NULL){

        }
        regenerateList(hand);
        *centerError = 0;
        calculateScore();
    }else{
        *valid = 0;
        resetState(hand);
    }

    /*else if(checkWord()){
        *valid = 1;
        for(;zz<7;zz++){
            rst[zz].ii = -1;
            rst[zz].jj = -1;
        }
        if(hand->first == NULL){

        }
        regenerateList(hand);
        *centerError = 0;
    }else{
        *valid = 0;
        resetState(hand);
    }*/


}

void resetState(HandList *hand){
    int ii, jj, zz;
    for(zz=0;zz<7;zz++){
        ii = rst[zz].ii;
        jj = rst[zz].jj;
        if(ii!=-1&&jj!=-1){
            //SDL_Log("%c", Stones[board[ii][jj].Stone].name);
            board[ii][jj].Stone = -1;
            rst[zz].ii = -1;
            rst[zz].jj = -1;
        }


    }
    SDL_Log("cikluson tul");
    initWord();
    resetList(hand);
}

void mixLetters(HandList *hand, int *centerError, int *valid){
    int ii=0;
    HandItem *temp = hand->first;
    if(temp == NULL){
        enterWord(hand, centerError, valid);
    }else{
        ii = hand->listSize;
        for(;temp != NULL; temp=temp->next){
            RandTable[temp->no] = 0;
            ii = rand()%100;
            if(RandTable[ii] != 0){
                if(ii > 0) ii--;
                else ii = 99;
                // usedStones++;
            }else if(RandTable[ii] == 0){
                temp->no = ii;
                //SDL_Log("%d", ii);
                RandTable[ii] = 1;
            }
        }
    }
}
