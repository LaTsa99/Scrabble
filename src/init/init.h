#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "../import/stones.h"
#include "../assets/board.h"
#include <SDL2/SDL2_gfxPrimitives.h>

void Game_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer,char* board_src);
void drawTitle(int width, int height, int x, int y, SDL_Window *window, SDL_Renderer *renderer);

#endif // INIT_H_INCLUDED
