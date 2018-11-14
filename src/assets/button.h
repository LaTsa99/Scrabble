#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <stdbool.h>


typedef struct{
    SDL_Rect draw_rect;
    struct {
        unsigned int r, g, b, a;
    }color;

    bool pressed;
}t_button;

void button_process_event(t_button *btn, const SDL_Event *ev);
bool button(SDL_Renderer *r, t_button *btn);

#endif // BUTTON_H
