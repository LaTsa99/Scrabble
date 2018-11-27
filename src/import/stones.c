#include "stones.h"

void generateStones(){
    int ret, len;

    ret = importStones(&len);
    if(ret == -1){
        SDL_Log("Stones: couldn't find sources!");
        exit(-1);
    } else if(ret == -2){
        SDL_Log("Stones: couldn't allocate memory for Stones array!");
        exit(-1);
    }
}

int importStones(int* len){
    int ii=0, t_Stones_size = sizeof(t_Stones);
    FILE* file = NULL;

    file = fopen("stones_en.latsa", "rb");
    *len = 100;

    if(file == NULL){
        SDL_Log("Error: Couldn't open the 'latsa' file: %s", SDL_GetError());
        exit(1);
    }

    Stones = (t_Stones *)malloc((*len) * t_Stones_size);
    if(Stones == NULL)return -2;

    for(ii=0;ii<*len;ii++){
        fscanf(file,"%c;%d;%d;%d;", &Stones[ii].name, &Stones[ii].pts, &Stones[ii].x, &Stones[ii].y);

        #if DEBUG == 1
            printf("%c %d\n", Stones[ii].name,Stones[ii].pts);
        #endif
    }
    fclose(file);
    return 0;
}
