#include "word.h"


bool checkWord(char *line, int vert, int linenumber, t_board board[15][15]){
    char* thisWord;
    int ii=0, jj, kk;
    bool correct = true;
    int cnt=0;
    for(;ii<15;ii++){
        if(line[ii] != '1'){
            cnt++;
        } else if(line[ii] == '1' && cnt >1){
            jj = ii - cnt;
            kk=0;
            thisWord = (char *)malloc(cnt+1);
            for(;jj < ii;jj++, kk++){
                thisWord[kk] = line[jj];
            }
            thisWord[cnt] = '\0';
            if(!checkDictionary(thisWord)){
                free(thisWord);
                return false;
            }
            cnt = 0;
        }else if(line[ii] == '1' && cnt == 1){
            if(vert){
                if(linenumber > 0)
                    if(board[linenumber-1][ii-1].Stone != -1 || board[linenumber+1][ii-1].Stone != -1){
                        cnt = 0;
                    }else return false;
                else
                    if(board[linenumber+1][ii-1].Stone != -1){
                        cnt = 0;
                    }else return false;
            }else{
                if(linenumber > 0)
                    if(board[ii-1][linenumber-1].Stone != -1 || board[ii-1][linenumber+1].Stone != -1){
                        cnt = 0;
                    }else return false;
                else
                    if(board[ii-1][linenumber+1].Stone != -1)
                        cnt = 0;
                    else return false;
            }
        }
    }
    free(thisWord);
    return correct;
}


bool wordCmp(char* buffer, char* thisWord){
    int ii=0;
    while(thisWord[ii]!= '\0'){
        if(buffer[ii]!= thisWord[ii]) return false;
        ii++;
    }
    if(thisWord[ii] == '\0' && buffer[ii] != '\n') return false;
    return true;
}

bool checkDictionary(char *word){
    FILE *fp;
    char buffer[25];
    bool found = false;
    fp = fopen("2of4brif.txt", "r");
    if(fp == NULL){
        SDL_Log("Couldn't open the dictionary file: %s", SDL_GetError());
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), fp) && !found){
        strupr(buffer);
        if(wordCmp(buffer, word)){
            found = true;
        }
    }

    fclose(fp);
    return found;
}
