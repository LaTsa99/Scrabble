#include "events.h"



void enterWord(HandList *hand, t_board board[15][15], int *score, char *score_str, t_Stones *Stones, previous_step *rst, eventTable *events, int *RandTable, int *prev){
    int ii,jj, zz = 0;
    char line1[16];
    char line2[16];
    bool ok = true;

    line1[15] = line2[15] = '\0';

    if(board[7][7].Stone == -1){
        resetState(hand, board, &(events->connected), Stones, rst, RandTable, prev);
        events->centerError = 1;
    }else if(events->first == 0 && events->connected == 0){
        events->illegal = 1;
        resetState(hand, board, &(events->connected), Stones, rst, RandTable, prev);
    }else{
        if(events->illegal == 1) events->illegal = 0;
        for(ii = 0;ii < 15; ii++){
            for(jj = 0;jj < 15; jj++){
                if(board[ii][jj].Stone != -1){
                    line1[jj] = Stones[board[ii][jj].Stone].name;
                }else{
                    line1[jj] = '1';

                }
                if(board[jj][ii].Stone != -1){
                    line2[jj] = Stones[board[jj][ii].Stone].name;
                }else{
                    line2[jj] = '1';
                }
            }
            if(!checkWord(line1, 1, ii, board) || !checkWord(line2, 0, ii, board)) ok = false;
        }
            if(ok){
                events->valid = 1;
                for(;zz<7;zz++){
                    rst[zz].ii = -1;
                    rst[zz].jj = -1;
                }
                if(hand->first == NULL){

                }
                regenerateList(hand, RandTable, prev);
                events->centerError = 0;
                calculateScore(board, score, score_str, Stones);
                if(events->first == 1) events->first = 0;
                events->connected = 0;
            }else{
                events->valid = 0;
                resetState(hand, board, &(events->connected), Stones, rst, RandTable, prev);
                }
    }
}

void resetState(HandList *hand, t_board board[15][15], int *connected, t_Stones *Stones, previous_step *rst, int *RandTable, int *prev){
    int ii, jj, zz;
    for(zz=0;zz<7;zz++){
        ii = rst[zz].ii;
        jj = rst[zz].jj;
        if(board[ii][jj].Stone == 98 || board[ii][jj].Stone == 98){
            Stones[board[ii][jj].Stone].name = 'j';
            Stones[board[ii][jj].Stone].x = 664;
            Stones[board[ii][jj].Stone].y = 65;
        }
        if(ii!=-1&&jj!=-1){
            board[ii][jj].Stone = -1;
            rst[zz].ii = -1;
            rst[zz].jj = -1;
        }


    }
    resetList(hand, RandTable, prev);
    *connected = 0;
}

void mixLetters(HandList *hand, t_board board[15][15], int *score, char *score_str, t_Stones *Stones, previous_step *rst, eventTable *events, int *RandTable, int *prev){
    int ii=0;
    HandItem *temp = hand->first;
    if(temp == NULL){
        enterWord(hand, board, score, score_str, Stones, rst, events, RandTable, prev);
    }else{

        ii = hand->listSize;
        for(;temp != NULL; temp=temp->next){
            RandTable[temp->no] = 0;
            ii = rand()%100;
            if(RandTable[ii] != 0){
                if(ii > 0) ii--;
                else ii = 99;
            }else if(RandTable[ii] == 0){
                temp->no = ii;
                RandTable[ii] = 1;
                prev[temp->index] = ii;
            }

    }
}
}

void changeTile(HandList *hand, int *RandTable, int *prev, int index){
    int ii=0;
    HandItem *temp = hand->first;

    for(;temp->index != index; temp = temp->next){
        ii++;
    }
    RandTable[temp->no] = 0;
    ii = rand()%100;
    if(RandTable[ii] != 0){
        if(ii > 0) ii--;
        else ii = 99;
    }else if(RandTable[ii] == 0){
        temp->no = ii;
        RandTable[ii] = 1;
        prev[temp->index] = ii;
    }
}
