#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "../assets/hand.h"
#include "../assets/board.h"
//#include "../assets/button.h"

bool isThatInHand(SDL_Event event, int *no, HandList *hand, int *index);
bool isOnTable(SDL_Event event, HandList *hand, int index, int *drawX, int *drawY);
//bool isOnResetButton(SDL_Event event, t_button *reset);

#endif // MOUSE_H_INCLUDED
