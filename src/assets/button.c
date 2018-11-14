#include "button.h"

void button_process_event(t_button *btn, const SDL_Event *ev){
    if(ev->type == SDL_MOUSEBUTTONDOWN){
        if(ev->button.button == SDL_BUTTON_LEFT &&
           ev->button.x >= btn->draw_rect.x &&
           ev->button.x <= (btn->draw_rect.x + btn->draw_rect.w) &&
           ev->button.y >= btn->draw_rect.y &&
           ev->button.y <= (btn->draw_rect.y + btn->draw_rect.h)){
            btn->pressed = true;
           }
    }
}

bool button(SDL_Renderer *r, t_button *btn){
    SDL_SetRenderDrawColor(r, btn->color.r, btn->color.g, btn->color.b, btn->color.a);
    SDL_RenderFillRect(r, &btn->draw_rect);

    if(btn->pressed){
        btn->pressed = false;
        return true;
    }
    return false;
}
