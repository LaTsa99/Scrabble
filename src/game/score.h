#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <string.h>
#include "../import/stones.h"
#include "../assets/board.h"



void calculateScore(t_board board[15][15], int *score, char *score_str, t_Stones *Stone);

#endif // SCORE_H_INCLUDED
