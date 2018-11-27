#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "../import/stones.h"

typedef struct{
    int x;
    int y;
    t_Stones Stone;
}t_board;

t_board board[15][15];

void generateBoard(SDL_Renderer *r, char* src);
void defineBoard();

#endif // BOARD_H_INCLUDED
