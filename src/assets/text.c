#include "text.h"

void initFont(TTF_Font **font){
    TTF_Init();
    *font = TTF_OpenFont("C:\\Windows\\Fonts\\BAUHS93.ttf", 32);
    if(font == NULL){
        SDL_Log("Error: Couldn't open font file: %s", SDL_GetError());
        exit(1);
    }
}

void drawText(SDL_Renderer *renderer, TTF_Font *font, int posX, int posY, int width, int height, char *text){
    SDL_Color white = {255,255,255};
    SDL_Color black = {0,0,0};

    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    SDL_Rect pos = {posX,posY,width,height};

    if(text == NULL){
        SDL_Log("text az null baszod");
        exit(1);
    }

    if(font == NULL){
        SDL_Log("nincs font baszod");
    }


    textSurface = TTF_RenderText_Shaded(font,text,white,black);
    if(textSurface == NULL){
        SDL_Log("Couldnt make textszar");
        exit(1);
    };
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, &pos);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}
