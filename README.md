# Deck

A project written entirely in C, designed to provide a deck of playing cards (excluding jokers) and the methods to modify and or access the deck created.

## Methods

### CreateDeck()

Creates a deck instance and returns a pointer to its location on the heap. Each deck created will be preset with cards. From Ace to King, starting with Spade and ending with Clubs.

```C
int main()
{
    // Creates a Deck, assigned to a double pointer 'DeckPtr'
    char **DeckPtr = CreateDeck();

    // Access each card within the deck via an array of DeckPtr, range is 0-51 per deck
    DeckPtr[0];

    printf("%s", DeckPtr[0]);
}
```

### ShuffleDeck()

Swaps 2 different and random cards within the deck a variable amount of times. With enough swaps, the deck is effectively shuffled.

```C
int main()
{
    // Prerequisite code
    char **DeckPtr = CreateDeck();

    // Requires (DeckPtr) created by CreateDeck() and the amount of (times) to swap random cards.
    ShuffleDeck(DeckPtr, 100);
}
```

### DestroyDeck()

Destroys deck instance created by CreateDeck(). Required for efficient memory management.

```C
int main()
{
    // Prerequisite code
    char **DeckPtr = CreateDeck();

    // Requires (DeckPtr) created by CreateDeck(). Only destroys the deck provided, other instances are not touched.
    DestroyDeck(DeckPtr);
}
```
