#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "../import/stones.h"
#include "../assets/board.h"
#include "../assets/text.h"
#include "../assets/hand.h"
//#include "../assets/button.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>

void Game_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer, HandList *hand, TTF_Font **font);

#endif // INIT_H_INCLUDED
