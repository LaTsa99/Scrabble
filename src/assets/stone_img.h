#ifndef STONE_IMG_H_INCLUDED
#define STONE_IMG_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "../import/stones.h"

void drawStone(SDL_Renderer *r, char *src, int no, int x, int y, int width, int height, t_Stones *Stones);

#endif // STONE_IMG_H_INCLUDED
