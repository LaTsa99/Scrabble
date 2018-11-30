#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

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

letters word[15];

void initWord();
bool checkWord(char *line);
bool rowOrColumn(int *RoC);
void sortWord(int RoC);
void swapWordItem(letters *a, letters *b);
bool wordCmp(char* buffer, char* thisWord);
bool checkDictionary(char *word);

#endif // WORD_H_INCLUDED
