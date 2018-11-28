#include "button.h"

t_button ResetButton ={"Reset", false, false, 1, 1000, 500};

void drawButton(SDL_Renderer *renderer, TTF_Font *font, t_button *button){
    drawText(renderer, font, button->x, button->y, 300, 50, button->label);
}
