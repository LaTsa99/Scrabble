#include "score.h"

int score = 0;
char score_str[5] = "0";

void calculateScore(){
    int ii, jj;
    score = 0;
    for(ii = 0;ii < 15; ii++){
        for(jj = 0;jj < 15;jj++){
                if(board[ii][jj].Stone != -1)
                    score += Stones[board[ii][jj].Stone].pts;
        }
    }

    itoa(score,score_str,10);
}
