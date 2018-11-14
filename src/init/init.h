#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "../import/stones.h"
#include <SDL2/SDL2_gfxPrimitives.h>

void Game_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer,char* lang);
void Control_init(int width, int height, SDL_Window **pwindow, SDL_Renderer **prenderer);

#endif // INIT_H_INCLUDED
