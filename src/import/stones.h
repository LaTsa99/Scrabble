#ifndef STONES_H_INCLUDED
#define STONES_H_INCLUDED

#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


typedef struct{
    char name;
    int pts;
}t_Stones;

t_Stones *Stones;

void generateStones(char* language);
int importStones(char* language);

#endif // STONES_H_INCLUDED
