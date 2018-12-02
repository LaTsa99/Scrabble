#include "stone_img.h"

//draws tile on the board
void drawStone(SDL_Renderer *r, char *src, int no, int x, int y, int width, int height, t_Stones *Stones){
    //imports the png, which contains the textures of the tiles
    SDL_Texture *stone = IMG_LoadTexture(r,src);
    if(stone == NULL){
        SDL_Log("Stone_img: Couldn't import stones(...).png: %s", SDL_GetError());
        exit(1);
    }

    //selects the tile from the texture, sends it to the renderer the frees memory
    SDL_Rect source = {Stones[no].x, Stones[no].y, 65, 65};
    SDL_Rect dest = {x, y, width, height};
    SDL_RenderCopy(r, stone, &source, &dest);
    SDL_DestroyTexture(stone);

}
