#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include "../assets/hand.h"
#include "../assets/board.h"
#include <stdbool.h>

void enterWord(HandList *hand, int *centerError);
void resetState();
void mixLetters();

#endif // EVENTS_H_INCLUDED
