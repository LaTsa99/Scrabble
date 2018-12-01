#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../assets/board.h"
#include "../assets/text.h"
#include "../assets/hand.h"
#include "score.h"
#include "events.h"


void refreshRenderer(SDL_Renderer *renderer, TTF_Font *font, HandList *hand, t_board board[15][15], char *score_str, t_Stones *Stones, eventTable *events, HandPosition *posOfHands);
bool input_text(char *dest, size_t hossz, SDL_Rect teglalap, SDL_Color hatter, SDL_Color szoveg, TTF_Font *font, SDL_Renderer *renderer, t_Stones *Stones);
#endif // RENDER_H_INCLUDED
