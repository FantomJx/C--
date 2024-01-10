#include "mystrings.h"
#include <stdio.h>

int main(int argc, char **argv){
    if(argc != 2){
        printf("Error: invalid input!");
    }

    char* inputString = argv[1];
    int lenght = strlength(inputString);
    printf("Len is %d", lenght);
    return 0;
}
