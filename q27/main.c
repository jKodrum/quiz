#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDNUM 52

int perfectRand(int lower, int upper)
{
    if (upper<lower) {
        int t = lower;
        lower = upper;
        upper = t;
    }
    int range = upper - lower;
    return (double)rand() / ((double)RAND_MAX+1) * range + lower;
}

void deal()
{
    int cards[CARDNUM], deck[CARDNUM];
    // init deck
    for (int i=0; i<CARDNUM; i++)
        deck[i] = i;

    // dealing
    for (int i=0; i<CARDNUM; i++) {
        int deck_i = perfectRand(0, CARDNUM-i);
        cards[i] = deck[deck_i];
        for (int j=deck_i; j<CARDNUM-i-1; j++)
            deck[j] = deck[j+1];
    }

    // print cards
    for (int i=0; i<CARDNUM; i++)
        printf("%d ", cards[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    deal();
    return 0;
}
