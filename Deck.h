#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef DeckSize
#define DeckSize 52
#endif

#ifndef MaxStrLen
#define MaxStrLen 17
#endif

#ifndef DECK_H_
#define DECK_H_

char** CreateDeck();
void ShuffleDeck(char**, int);
void DestroyDeck(char**);

#endif