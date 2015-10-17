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

int cards[CARDNUM], deck[CARDNUM];
void deal(int remain)
{
    if (remain<1) return;

    int deck_i = perfectRand(0, remain);
    cards[remain-1] = deck[deck_i];
    for (int i=deck_i; i<remain-1; i++) deck[i] = deck[i+1];
    deal(remain-1);
}

int main()
{
    srand(time(NULL));
    // init deck
    for (int i=0; i<CARDNUM; i++)
        deck[i] = i;

    deal(CARDNUM);
    // print cards
    for (int i=0; i<CARDNUM; i++)
        printf("%d ", cards[i]);
    printf("\n");
    return 0;
}
