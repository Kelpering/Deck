#include "Deck.h"

/*
 * Creates: a Deck of Cards within the heap. The program then fills the heap with a non-shuffled, valid deck of cards (excluding jokers).
 * 
 * Returns: an array of pointers that hold strings.
*/
char ** CreateDeck()
{
        //? Initialize Random functions for shuffle
    //! Initializes it for each deck, this is inefficient but removes excess code in main.
    __time_t t;
    srand((unsigned) time(&t));

        //? Allocate heap for Deck
    //* Allocate new memory for an array of size (DeckSize). Each holds a pointer
    char **NewDeckPtr = malloc(DeckSize * sizeof(char *));
    //* For every index in NewDeckPtr
    for (int i = 0; i < DeckSize; i++)
    {
        //* Set index to a newly allocated string of size (StrLen + Null Terminator)
        NewDeckPtr[i] = (char *) malloc (MaxStrLen+1);
    }
    //! To free, free each index in NewDeckPtr, then NewDeckPtr
    //* Ex: free(NewDeckPtr[0])... free(NewDeckPtr[51]); free(NewDeckPtr);

        //? Fill Deck
    enum Suit 
    {
        Spade = 0,
        Heart,
        Diamond,
        Club
    };

    enum Card
    {
        Ace = 1,
        Jack = 11,
        Queen = 12,
        King = 13
    };

    char Deck[52][30];
    enum Suit;
    enum Card;
    int count = 0;
    for (int suit = 0; suit < 4; suit++) //0-3
    {
        for (int j = 1; j <= 13; j++)   //1-13
        {
            char Temp[MaxStrLen];
            switch (j)
            {
            case Ace:
                sprintf(Temp, "Ace of ");
                break;
            case Jack:
                sprintf(Temp, "Jack of ");
                break;
            case Queen:
                sprintf(Temp, "Queen of ");
                break;
            case King:
                sprintf(Temp, "King of ");
                break;
            default:
                sprintf(Temp, "%d of ", j);
                break;
            }
            switch(suit)
            {
                case Spade:
                    strcat(Temp, "Spades");
                    break;
                case Heart:
                    strcat(Temp, "Hearts");
                    break;
                case Diamond:
                    strcat(Temp, "Diamonds");
                    break;
                case Club:
                    strcat(Temp, "Clubs");
                    break;
            }
            //* Copy the current Temp string over to NewDeckPtr[index]
            strcpy(NewDeckPtr[count], Temp);
            //printf("%s \n", NewDeckPtr[count]);
            count++;
        }
    }
    //* Returns array of pointers
    //! To free, free every pointer first, then free the array itself.
    return NewDeckPtr;
}
/*
 * Swaps 2 cards within the deck (times) amount of times
 * 
 * returns: Nothing
*/
void ShuffleDeck(char **Deck, int times)
{
            //? Shuffle the entire deck by swapping 2 cards (times) amount of times.
        for (int i = 0; i < times; i++)
        {
            //* Choose both cards to swap
            //* Numbers range from 0-51
            int DestNum = rand() % (DeckSize);
            int SrcNum = rand() % (DeckSize);
            
            //* Copy DestNum index's pointer.
            char *TempDest = Deck[DestNum];
            

            //* Overwrite DestNum index's pointer with SrcNum's index pointer.
            Deck[DestNum] = Deck[SrcNum];

            //* Use copy of DestNum's old pointer to overwrite SrcNum's old pointer.
            Deck[SrcNum] = TempDest;

            //* The pointers at index Destnum and SrcNum are swapped, thereby swapping the 2 cards.
        }

    return;
}

/*
 * Frees all memory of the provided Deck, thereby safely destroying it.
 * 
 * returns: Nothing
*/
void DestroyDeck(char **Deck)
{
    for (int i = 0; i < DeckSize; i++)
    {
        free(Deck[i]);
    }
    free(Deck);
    return;
}