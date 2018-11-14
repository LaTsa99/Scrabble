#include "stones.h"

void generateStones(char* language){
    int ret;

    setlocale(LC_ALL, "de_DE.utf8");

    ret = importStones(language);
    if(ret == -1){
        SDL_Log("Stones: couldn't find sources!");
        exit(-1);
    } else if(ret == -2){
        SDL_Log("Stones: couldn't allocate memory for Stones array!");
        exit(-1);
    }
}

int importStones(char* language){
    int ii=0, len, t_Stones_size = 5;
    char temp[6];
    FILE* file = NULL;

    if(strcmp(language,"en") == 0){
        file = fopen("stones_en.txt", "r");
        len = 100;
    }else if(strcmp(language,"de") == 0){
        file = fopen("stones_de.txt", "r");
        len = 102;
    }

    if(file == NULL) return -1;

    Stones = (t_Stones *)malloc(len * t_Stones_size);
    if(Stones == NULL)return -2;
    ii = 0;
    while(fgets(temp,sizeof(temp),file) != NULL){
        //printf("%s\n", temp);
        Stones[ii].name = temp[0];
        temp[strcspn(temp, "\n")] = '\0';
        if(temp[2] == '0'){
            Stones[ii].pts = temp[3] - '0';
        }else{
            Stones[ii].pts = 10;
        }
        //printf("%c %d\n", Stones[ii].name,Stones[ii].pts);
        ii++;
    }
    fclose(file);
    return 0;
}
