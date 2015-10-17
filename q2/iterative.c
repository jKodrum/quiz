#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX_LEN 100000

char smallest_character(char arr[], char c)
{
    for (int i=0; arr[i]!='\0'; i++)
        if (arr[i] > c)  return arr[i];
    return arr[0];
}

int main(int argc, char *argv[])
{
    char str[MAX_LEN];
    char given;
    FILE *fp;
    assert(fp=fopen(argv[1], "r"));
    while (fscanf(fp,"%s %c", str, &given)==2) {

        /* Print input message
        assert(printf("Input: ['%c'", str[0]));
        for (char *c=str+1; *c; c++)
            printf(", '%c'", *c);
        printf("], '%c'\n", given);
        */

        //printf("Output: '%c'\n", smallest_character(str, given));
        printf("%c\n", smallest_character(str, given));
    }

    return 0;
}
