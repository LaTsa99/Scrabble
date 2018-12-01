#include "score.h"


void calculateScore(t_board board[15][15], int *score, char* score_str, t_Stones *Stones){
    int ii, jj;
    *score = 0;
    for(ii = 0;ii < 15; ii++){
        for(jj = 0;jj < 15;jj++){
                if(board[ii][jj].Stone != -1)
                    *score += Stones[board[ii][jj].Stone].pts;
        }
    }

    itoa(*score,score_str,10);
}
