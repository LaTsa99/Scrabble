#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <string.h>
#include "../assets/board.h"
#include "../assets/text.h"
#include "../assets/hand.h"
#include "score.h"
//#include "../assets/button.h"

void refreshRenderer(SDL_Renderer *renderer, TTF_Font *font, HandList *hand, int centerError, int valid);

#endif // RENDER_H_INCLUDED
