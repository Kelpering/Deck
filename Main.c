#include <stdio.h>
#include "Deck.h"

int main()
{
    //* Creates Deck
    char **DeckPtr = CreateDeck();

    //* Access Deck
    //DeckPtr[0];

    //* Shuffles Deck
    printf("\nBefore shuffle:\nDeck index 0: \"%s\" \n", DeckPtr[0]);
    ShuffleDeck(DeckPtr, 100);
    printf("\nAfter shuffle:\nDeck index 0: \"%s\" \n\n", DeckPtr[0]);

    //* Frees Deck
    DestroyDeck(DeckPtr);

    return 0;
}