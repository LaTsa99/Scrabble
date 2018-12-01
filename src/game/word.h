#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include "../assets/board.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>


struct letters{
    char letter;
    int boardX;
    int boardY;
};

typedef struct letters letters;


bool checkWord(char *line, int vert, int linenumber, t_board board[15][15]);
bool wordCmp(char* buffer, char* thisWord);
bool checkDictionary(char *word);

#endif // WORD_H_INCLUDED
