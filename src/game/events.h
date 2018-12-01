#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include "../assets/hand.h"
#include "../assets/board.h"
#include "score.h"
#include "word.h"

#include <stdbool.h>

struct eventTable{
    int centerError;
    int valid;
    int first;
    int connected;
    int illegal;
    int jokerInput;
    int currentJoker;
    int remix;
};

typedef struct eventTable eventTable;

void enterWord(HandList *hand, t_board board[15][15], int *score, char *score_str, t_Stones *Stones, previous_step *rst, eventTable *events, int *RandTable, int *prev);
void resetState(HandList *hand, t_board board[15][15], int *connected, t_Stones *Stones, previous_step *rst, int *RandTable, int *prev);
void mixLetters(HandList *hand, t_board board[15][15], int *score, char *score_str, t_Stones *Stones, previous_step *rst, eventTable *events, int *RandTable, int *prev);
void changeTile(HandList *hand, int *RandTable, int *prev, int index);

#endif // EVENTS_H_INCLUDED
