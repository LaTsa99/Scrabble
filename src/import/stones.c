#include "stones.h"

void generateStones(t_Stones *Stones){
    int ii, len = 100;
    FILE* file = NULL;

    file = fopen("stones_en.latsa", "rb");

    if(file == NULL){
        SDL_Log("Stones: Couldn't open the 'latsa' file: %s", SDL_GetError());
        exit(1);
    }


    for(ii=0;ii<len;ii++){
        fscanf(file,"%c;%d;%d;%d;", &Stones[ii].name, &Stones[ii].pts, &Stones[ii].x, &Stones[ii].y);
    }

    fclose(file);
}
