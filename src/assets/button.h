#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "text.h"


struct t_button{
    char label[10];
    bool hover;
    bool pressed;
    int color;
    int x;
    int y;
};

typedef struct t_button t_button;
extern t_button ResetButton;

void drawButton(SDL_Renderer *renderer,TTF_Font *font, t_button *button);

#endif // BUTTON_H
