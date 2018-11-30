#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "../import/stones.h"

struct t_board{
    int x;
    int y;
    int Stone;
};

struct previous_step{
    int ii;
    int jj;
};

typedef struct t_board t_board;
typedef struct previous_step previous_step;
t_board board[15][15];
previous_step rst[7];


void generateBoard(SDL_Renderer *r, char* src);
void defineBoard();

#endif // BOARD_H_INCLUDED
