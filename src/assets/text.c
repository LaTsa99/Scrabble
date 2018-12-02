#include "text.h"

//initializes font
void initFont(TTF_Font **font){
    TTF_Init();
    //opens front from HDD
    *font = TTF_OpenFont("C:\\Windows\\Fonts\\BAUHS93.ttf", 32);
    if(font == NULL){
        SDL_Log("Couldn't open font file: %s", SDL_GetError());
        exit(1);
    }
}

//draws text on the screen
void drawText(SDL_Renderer *renderer, TTF_Font *font, int posX, int posY, int width, int height, char *text){
    SDL_Color white = {255,255,255};
    SDL_Color black = {0,0,0};

    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    SDL_Rect pos = {posX,posY,width,height};

    //Creates text
    textSurface = TTF_RenderText_Shaded(font,text,white,black);
    if(textSurface == NULL){
        SDL_Log("Couldn't create text: %s", SDL_GetError());
        exit(1);
    };

    //sends the text to the renderer
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, &pos);

    //freeing memory
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}
