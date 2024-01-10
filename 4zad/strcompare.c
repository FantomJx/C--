#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv) {
    if (argc != 3)
    {
        fprintf(stderr, "Error in input\n");
        return 1;
    }

    char* firstString = argv[1];
    char* secondString = argv[2];
    if(strlength(firstString) >= 50 || strlength(secondString) >= 50)
    {
        printf("Smaller strings!");
    }
    int result = strcompare(firstString, secondString);
    printf("%d", result);
    return 0;
}
