#include "word.h"

void initWord(){
    int ii;
    for(ii=0;ii<15;ii++){
        word[ii].letter = '\0';
        word[ii].boardX = -1;
        word[ii].boardY = -1;
    }
}

bool checkWord(char *line){
    FILE *fp;
    char buffer[25];
    char* thisWord;
    int ii=0, jj, kk, len=0;
    bool correct = true;
    int RoC;
    int cnt=0;
    SDL_Log("%s", line);
    for(;ii<15;ii++){
        //SDL_Log("%d", cnt);
        if(line[ii] != '1') cnt++;
        else if(line[ii] == '1' && cnt >1){

            jj = ii - cnt;
            kk=0;
            thisWord = (char *)malloc(cnt+1);
            for(;jj < ii;jj++, kk++){
                thisWord[kk] = line[jj];
            }
            thisWord[cnt] = '\0';
            //SDL_Log("%s", thisWord);
            if(!checkDictionary(thisWord)){
                free(thisWord);
                return false;
            }
            cnt = 0;
        }else if(line[ii] == '1' && cnt <= 1){
            cnt = 0;
        }
    }
    /*
    //SDL_Log("bejut");
    if(!rowOrColumn(&RoC)) return false;
    //SDL_Log("igaz vot");
    sortWord(RoC);
    //SDL_Log("vot sort");
    while(word[len].boardX != -1 && len < 15)
        len++;
    //SDL_Log("meretezes megvot");
    thisWord = (char*)malloc(len);
    while(word[ii].boardX != -1 && ii < len){
         thisWord[ii] = word[ii].letter;
         ii++;
    }

    //SDL_Log("masolas megvot");
    thisWord[len] = '\0';
    */


    free(thisWord);
    initWord();
    return correct;
}

bool rowOrColumn(int *RoC){
    int ii,len=0, x = word[0].boardX, y = word[0].boardY;
    bool sameX = true;
    bool sameY = true;
    while(word[len].boardX != -1) len++;
    for(ii = 1;ii < len;ii++){
        if(word[ii].boardX != x) sameX = false;
        SDL_Log("%d, %d", word[ii].boardX, x);
        if(word[ii].boardY != y) sameY = false;
        SDL_Log("%d, %d", word[ii].boardX, y);
    }
    if(sameX) *RoC = 1;
    if(sameY) *RoC = 2;
    return (sameX || sameY);
}


void sortWord(int RoC){
    int ii, jj, len = 0;
    while(word[len].boardX != -1)
        len++;
    if(RoC == 1){
        for(ii=0;ii<len;ii++){
            for(jj = len-1;jj>ii;jj--){
                if(word[jj].boardY < word[ii].boardY){
                    swapWordItem(&word[jj], &word[ii]);
                }
            }
        }
    }else if(RoC == 2){
        for(ii=0;ii<len;ii++){
                for(jj = len-1;jj>ii;jj--){
                    if(word[jj].boardX < word[ii].boardX){
                        swapWordItem(&word[jj], &word[ii]);
                    }
                }
            }
    }
}

void swapWordItem(letters *a, letters *b){
    int temp;
    char tempc;

    tempc = a->letter;
    a -> letter = b->letter;
    b->letter = tempc;

    temp = a->boardX;
    a->boardX = b->boardX;
    b->boardX = temp;

    temp = a->boardY;
    a->boardY = b->boardY;
    b->boardY = temp;
}

bool wordCmp(char* buffer, char* thisWord){
    int ii=0;
    while(buffer[ii]!= '\n'){
        if(buffer[ii]!= thisWord[ii]) return false;
        ii++;
    }
    return true;
}

bool checkDictionary(char *word){
    FILE *fp;
    char *buffer[25];
    bool found = false;

    fp = fopen("2of4brif.txt", "r");
    if(fp == NULL){
        SDL_Log("Couldn't open the dictionary file: %s", SDL_GetError());
        exit(1);
    }
    //SDL_Log("itt vok");

    while(fgets(buffer, sizeof(buffer), fp) && !found){
        strupr(buffer);
        //SDL_Log("%s, %s", buffer, thisWord);
        if(wordCmp(buffer, word)){
            found = true;
      //      SDL_Log("volt");
        }
    }
    //SDL_Log("talalhatta");

    fclose(fp);
    return found;
}
