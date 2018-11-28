#include "hand.h"

void drawHand(SDL_Renderer *renderer, HandList *hand, char* stn_src){
    int ii = 0;
    HandItem *jj = hand->first;

    if(jj != NULL){
        for(;jj != NULL;ii++, jj = jj->next){
            drawStone(renderer,stn_src, jj->no, posOfHands[ii].x, posOfHands[ii].y, 65, 65);
        }
    }
}

void initialHand(HandList *hand){
    int baseX = 900;
    int baseY = 200;
    int ii;

    for(ii=0;ii<100;ii++){
        RandTable[ii] = 0;
    }

    for(ii=0;ii<7;ii++){
        posOfHands[ii].x = baseX + (ii * 65);
        posOfHands[ii].y = baseY;
    }

    HandItem *temp;
    temp = (HandItem*)malloc(sizeof(HandItem));

    hand->listSize = 1;
    temp->index = 0;
    temp->prev = NULL;
    temp->next = NULL;

    ii = rand()%100;
    RandTable[ii] = 1;
    //usedStones++;
    temp->no = ii;
    prev[0] = temp->no;
    hand->first = temp;
    hand->last = temp;
    hand->listSize = 1;
    for(ii=1;ii<7;ii++){
        temp = addHand(hand, hand->last);
        prev[ii] = temp->no;
    }
}

HandItem* addHand(HandList *hand, HandItem *prevent){
    int ii;
    HandItem *newItem = (HandItem*)malloc(sizeof(HandItem));
    newItem->index = prevent->index + 1;
    ii = rand()%100;
    SDL_Log("%d", ii);
    if(RandTable[ii] != 0){
        if(ii > 0) ii--;
        else ii = 99;
        // usedStones++;
    }else if(RandTable[ii] == 0){
        newItem->no = ii;
        RandTable[ii] = 1;
    }

    newItem->no = ii;
    RandTable[ii] = 1;

    newItem->next = NULL;
    newItem->prev = prevent;

    prevent->next = newItem;
    hand->last = newItem;
    hand->listSize = hand->listSize + 1;
    return newItem;
}

HandItem* addHandReset(HandList *hand, HandItem *prevent){
    HandItem *newItem = (HandItem*)malloc(sizeof(HandItem));
    newItem->index = prevent->index + 1;

    newItem->no = prev[newItem->index];

    newItem->next = NULL;
    newItem->prev = prevent;

    prevent->next = newItem;
    hand->last = newItem;
    hand->listSize = hand->listSize + 1;
    return newItem;
}

void freeHand(HandItem *first){
    HandItem *ii, *temp;
    ii = first;
    while(ii != NULL){
        temp = ii;
        ii = ii->next;
        free(temp);
    }
}

void delHandItem(HandItem *first, int index, HandList *hand){
    int ii = first->index;
    HandItem *jj = first;
    while(ii<index && jj != NULL){
        ii++;
        jj = jj->next;
    }
    //SDL_Log("1");
    if(ii<=index){
        HandItem *prev_item, *next_item;
        //SDL_Log("2");
        if(jj->prev != NULL && jj->next != NULL){
            prev_item = jj->prev;
            next_item = jj->next;
            prev_item->next = next_item;
            next_item->prev = prev_item;
        }else if(jj->prev == NULL && jj->next != NULL){
            first = jj->next;
            first->prev = NULL;
            hand->first = first;
        }else if(jj->next == NULL && jj->prev != NULL){
            prev_item = jj->prev;
            prev_item->next = NULL;
            hand->last=prev_item;
        }else if(jj->next == NULL && jj->prev == NULL){
            hand->first = NULL;
            hand->last = NULL;
        }
        free(jj);
        reindexList(first);
        hand->listSize = hand->listSize - 1;
    }
}

void reindexList(HandItem *first){
    int ii;
    HandItem *jj;
    for(ii=0, jj=first; jj!=NULL;jj=jj->next){
        jj->index = ii++;
    }
}

void regenerateList(HandList *hand, HandItem *first){
    int ii, len;
    HandItem *temp;
    if(hand->listSize < 7){
        len = 7 - hand->listSize;
        for(ii=0;ii<len;ii++){
            temp = addHand(hand,hand->last);
            prev[ii] = temp->no;
        }
    }
}

void resetList(HandList *hand){
    int ii = 0;
    HandItem *temp;
    freeHand(hand->first);

    temp = (HandItem*)malloc(sizeof(HandItem));

    hand->listSize = 1;
    temp->index = 0;
    temp->prev = NULL;
    temp->next = NULL;


    temp->no = prev[ii];
    hand->first = temp;
    hand->last = temp;
    hand->listSize = 1;
    for(;ii<7;ii++){
        temp = addHandReset(hand, hand->last);
    }
}
