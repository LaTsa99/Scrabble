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

int RandTable[100];
HandPosition posOfHands[7];
int prev[7];

void drawHand(SDL_Renderer *renderer, HandList *hand, char* stn_src);
void initialHand(HandList *hand);
HandItem *addHand(HandList *hand, HandItem *prevent);
HandItem* addHandReset(HandList *hand, HandItem *prevent);
void freeHand(HandItem *first);
void delHandItem(HandItem *first, int index, HandList *hand);
void reindexList(HandItem *first);
void regenerateList(HandList *hand, HandItem *first);
void resetList(HandList *hand);

#endif // HAND_H_INCLUDED
