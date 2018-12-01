#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "word.h"
#include "../assets/hand.h"
#include "../assets/board.h"
#include "../import/stones.h"
#include "events.h"

bool isThatInHand(SDL_Event event, int *no, HandList *hand, int *index, HandPosition *posOfHands);
bool isOnTable(SDL_Event event, HandList *hand, int index, int *drawX, int *drawY, t_board board[15][15], t_Stones *Stones, eventTable *events, previous_step *rst);

#endif // MOUSE_H_INCLUDED
