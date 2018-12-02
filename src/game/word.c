#include "word.h"

//checks if characters in a line are valid
bool checkWord(char *line, int vert, int linenumber, t_board board[15][15]){
    char* thisWord = NULL;
    int ii=0, jj, kk;
    bool correct = true;
    int cnt=0;

    //go through the elements of the char array
    for(;ii<15;ii++){
        //looking for strings longer than 1 character
        if(line[ii] != '1'){
            cnt++;
        } else if(line[ii] == '1' && cnt >1){
            jj = ii - cnt;
            kk=0;
            //allocate memory for our temporary string
            thisWord = (char *)malloc(cnt+1);
            for(;jj < ii;jj++, kk++){
                thisWord[kk] = line[jj];
            }
            thisWord[cnt] = '\0';

            //send string to dictionary reader
            if(!checkDictionary(thisWord)){
                return false;
            }

            free(thisWord);
            cnt = 0;
        }else if(line[ii] == '1' && cnt == 1){
            //if there is only one character with no neighbors, check if it is in a crossword
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
    if(thisWord != NULL) free(thisWord);
    return correct;
}

//compares two words
bool wordCmp(char* buffer, char* thisWord){
    int ii=0;
    while(thisWord[ii]!= '\0'){
        if(buffer[ii]!= thisWord[ii]) return false;
        ii++;
    }
    //make sure, that they are the same length
    if(thisWord[ii] == '\0' && buffer[ii] != '\n') return false;
    return true;
}

//check if the word is in the dictionary
bool checkDictionary(char *word){
    FILE *fp;
    char buffer[25];
    bool found = false;

    //opening dictionary file
    fp = fopen("2of4brif.txt", "r");
    if(fp == NULL){
        SDL_Log("Couldn't open the dictionary file: %s", SDL_GetError());
        exit(1);
    }

    //go through file until match
    while(fgets(buffer, sizeof(buffer), fp) && !found){
        strupr(buffer);
        if(wordCmp(buffer, word)){
            found = true;
        }
    }

    fclose(fp);
    return found;
}
