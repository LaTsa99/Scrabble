#ifndef STONES_H_INCLUDED
#define STONES_H_INCLUDED

#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    char name;
    int pts;
    int x;
    int y;
}t_Stones;

t_Stones *Stones;

void generateStones();
int importStones(int *len);

#endif // STONES_H_INCLUDED
