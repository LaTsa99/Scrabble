#include "score.h"

//calculates the current score
void calculateScore(t_board board[15][15], int *score, char* score_str, t_Stones *Stones){
    int ii, jj;
    *score = 0;

    //goes through table, counting scores of tiles
    for(ii = 0;ii < 15; ii++){
        for(jj = 0;jj < 15;jj++){
                if(board[ii][jj].Stone != -1)
                    *score += Stones[board[ii][jj].Stone].pts;
        }
    }

    //makes string from score, so the program can write it on the window
    itoa(*score,score_str,10);
}
