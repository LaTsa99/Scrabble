#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
//#include "../init/init.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>

void initFont(TTF_Font **font);
void drawText(SDL_Renderer *renderer, TTF_Font *font, int posX, int posY, int width, int height, char *text);


#endif // TEXT_H_INCLUDED
