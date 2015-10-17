#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_STR 1000
#define MAX_LEN 100000

int uniformRand(int lower, int upper)
{
    if (upper<lower) {
        int t = lower;
        lower = upper;
        upper = t;
    }
    int range = upper - lower;
    return (double)rand() / ((double)RAND_MAX+1) * range + lower;
}

int main()
{
    srand(time(NULL));
    char str[MAX_LEN];
    int len;
    for (int i=0; i<TOTAL_STR; i++) {
        len = rand() % MAX_LEN;
        int j;
        char ch = 'a'+(char)uniformRand(0, 26);
        for (j=0; j<len; j++) {
            if (ch < 'z' && uniformRand(0, len/10) < 1) {
                char inc;
                if (uniformRand(0, 20) < 1)
                    inc = (char)uniformRand(1, 26);
                else
                    inc = (char)uniformRand(1, 5);
                ch = (ch+inc>'z') ? 'z' : ch+inc;
            }
            str[j] = ch;
        }
        str[j] = '\0';
        printf("%s %c\n", str, 'a'+(char)uniformRand(0, 26));
    }
    return 0;
}
