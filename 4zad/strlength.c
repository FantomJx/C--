#include "mystrings.h"
#include <stdio.h>

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Error: invalid input!\ns");
    }

    char* inputString = argv[1];
    int lenght = strlength(inputString);
    printf("Len is %d", lenght);
    return 0;
}
