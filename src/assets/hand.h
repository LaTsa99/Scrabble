#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include "../import/stones.h"
#include "stone_img.h"
#include "text.h"

#include <SDL2/SDL_ttf.h>
#include <time.h>

struct HandItem{
    int no;

    int index;
    struct HandItem *next;
    struct HandItem *prev;
};

struct HandList{
    int listSize;
    struct HandItem *first;
    struct HandItem *last;
};

struct HandPosition{
    int x;
    int y;
};

typedef struct HandList HandList;
typedef struct HandItem HandItem;
typedef struct HandPosition HandPosition;

void drawHand(SDL_Renderer *renderer, HandList *hand, char* stn_src, t_Stones *Stones, HandPosition *posOfHands);
void initialHand(HandList *hand, int *RandTable, HandPosition *posOfHands, int *prev);
HandItem* addHand(HandList *hand, HandItem *prevent, int *RandTable);
HandItem* addHandReset(HandList *hand, HandItem *prevent, int *prev);
void freeHand(HandItem *first);
void delHandItem(HandItem *first, int index, HandList *hand);
void reindexList(HandItem *first);
void regenerateList(HandList *hand, int *RandTable, int *prev);
void resetList(HandList *hand, int *RandTable, int *prev);

#endif // HAND_H_INCLUDED
