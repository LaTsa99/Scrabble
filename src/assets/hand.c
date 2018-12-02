#include "hand.h"

//draws the tiles in hand
void drawHand(SDL_Renderer *renderer, HandList *hand, char* stn_src, t_Stones *Stones, HandPosition *posOfHands){
    int ii = 0;
    HandItem *jj = hand->first;

    //sends every item from hand to the tile drawer
    if(jj != NULL){
        for(;jj != NULL;ii++, jj = jj->next){
            drawStone(renderer,stn_src, jj->no, posOfHands[ii].x, posOfHands[ii].y, 65, 65, Stones);
        }
    }
}

//creates the starting hand
void initialHand(HandList *hand, int *RandTable, HandPosition *posOfHands, int *prev){
    int baseX = 900;
    int baseY = 200;
    int ii;
    HandItem *temp;

    //sets every number in the random array free
    for(ii=0;ii<100;ii++){
        RandTable[ii] = 0;
    }

    //gives the positions of the tiles in hand
    for(ii=0;ii<7;ii++){
        posOfHands[ii].x = baseX + (ii * 65);
        posOfHands[ii].y = baseY;
    }

    //allocates memory for the first tile in hand
    temp = (HandItem*)malloc(sizeof(HandItem));

    //sets the first element of the handlist, which is a linked list
    hand->listSize = 1;
    temp->index = 0;
    temp->prev = NULL;
    temp->next = NULL;

    //sets the random number as the tile number and sets its status in randtable to used
    ii = rand()%100;
    RandTable[ii] = 1;


    temp->no = ii;
    prev[0] = temp->no;
    hand->first = temp;
    hand->last = temp;
    hand->listSize = 1;

    //adds six more tiles to the hand
    for(ii=1;ii<7;ii++){
        temp = addHand(hand, hand->last, RandTable);
        prev[ii] = temp->no;
    }
}

//linked list: adds tile to the hand
HandItem* addHand(HandList *hand, HandItem *prevent, int *RandTable){
    int ii;
    HandItem *newItem = (HandItem*)malloc(sizeof(HandItem));
    newItem->index = prevent->index + 1;
    ii = rand()%100;

    //makes sure the random number is not used yet
    if(RandTable[ii] != 0){
        if(ii > 0) ii--;
        else ii = 99;
    }else if(RandTable[ii] == 0){
        newItem->no = ii;
        RandTable[ii] = 1;
    }

    //creates new element
    newItem->no = ii;
    RandTable[ii] = 1;

    newItem->next = NULL;
    newItem->prev = prevent;

    //adds it to the linked list
    prevent->next = newItem;
    hand->last = newItem;
    hand->listSize = hand->listSize + 1;

    ii = 0;
    return newItem;
}

//linked list: adds the tile from the reset array
HandItem* addHandReset(HandList *hand, HandItem *prevent, int *prev){
    HandItem *newItem = (HandItem*)malloc(sizeof(HandItem));
    //sets the index
    newItem->index = prevent->index + 1;
    //sets the tile number from the previous hand
    newItem->no = prev[newItem->index];

    //adds it to the linked list
    newItem->next = NULL;
    newItem->prev = prevent;

    prevent->next = newItem;
    hand->last = newItem;
    hand->listSize = hand->listSize + 1;
    return newItem;
}

//linked list: frees the memory, that the linked list used
void freeHand(HandItem *first){
    HandItem *ii, *temp;
    ii = first;
    while(ii != NULL){
        temp = ii;
        ii = ii->next;
        free(temp);
    }
}

//linked list: deletes selected item from the list
void delHandItem(HandItem *first, int index, HandList *hand){
    int ii = first->index;
    HandItem *jj = first;
    //searches for the selected item
    while(ii<index && jj != NULL){
        ii++;
        jj = jj->next;
    }
    //if the index is still in the hand
    if(ii<=index){
        HandItem *prev_item, *next_item;
        if(jj->prev != NULL && jj->next != NULL){
            //if it's not the last, nor the first element of the list
            prev_item = jj->prev;
            next_item = jj->next;
            prev_item->next = next_item;
            next_item->prev = prev_item;
        }else if(jj->prev == NULL && jj->next != NULL){
            //if it's the first element
            first = jj->next;
            first->prev = NULL;
            hand->first = first;
        }else if(jj->next == NULL && jj->prev != NULL){
            //if it's the last element
            prev_item = jj->prev;
            prev_item->next = NULL;
            hand->last=prev_item;
        }else if(jj->next == NULL && jj->prev == NULL){
            //if it's the only element
            hand->first = NULL;
            hand->last = NULL;
        }
        //frees the memory allocated by the deleted item, then reindexes the elements of the list
        free(jj);
        reindexList(first);
        //decrement the size of the list
        hand->listSize = hand->listSize - 1;
    }
}

//linked list: reindexes the list
void reindexList(HandItem *first){
    int ii;
    HandItem *jj;
    //yeah, it reindexes the elements
    for(ii=0, jj=first; jj!=NULL;jj=jj->next){
        jj->index = ii++;
    }
}

//linked list: regenerates the list, i mean gives elements until there is 7 of them again
void regenerateList(HandList *hand, int *RandTable, int *prev){
    int ii, len;
    HandItem *temp;
    if(hand->last == NULL){
        //if there is no more elements
        //makes the first element manually
        temp = (HandItem*)malloc(sizeof(HandItem));
        temp->index = 0;
        ii = rand()%100;
        if(RandTable[ii] != 0){
            if(ii > 0) ii--;
            else ii = 99;
        }else if(RandTable[ii] == 0){
            temp->no = ii;
            RandTable[ii] = 1;
        }
        temp->prev = NULL;
        temp->next = NULL;
        hand->first = temp;
        hand->last = temp;
        hand->listSize = hand->listSize + 1;
    }
    //then simply adds new elements until there is 7 again
    if(hand->listSize < 7){
        len = 7 - hand->listSize;
        for(ii=0;ii<len;ii++){
            temp = addHand(hand,hand->last, RandTable);
            prev[ii] = temp->no;
        }
    }
    //gives the new elements to the array of previous elements
    for(ii=0, temp = hand->first; temp != NULL;ii++, temp = temp->next){
        prev[ii] = temp->no;
    }
}

//linked list: sets the list in its previous state
void resetList(HandList *hand, int *RandTable, int *prev){
    int ii = 0;
    HandItem *temp;
    //deletes current list
    freeHand(hand->first);

    //makes new one
    temp = (HandItem*)malloc(sizeof(HandItem));

    hand->listSize = 1;
    temp->index = 0;
    temp->prev = NULL;
    temp->next = NULL;


    temp->no = prev[ii++];
    hand->first = temp;
    hand->last = temp;
    hand->listSize = 1;
    for(;ii<7;ii++){
        temp = addHandReset(hand, hand->last, prev);
    }
}
