#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include "../assets/hand.h"
#include "../assets/board.h"
#include "score.h"
#include "word.h"
#include <stdbool.h>

void enterWord(HandList *hand, int *centerError, int *valid);
void resetState(HandList *hand);
void mixLetters(HandList *hand, int *centerError, int *valid);

#endif // EVENTS_H_INCLUDED
