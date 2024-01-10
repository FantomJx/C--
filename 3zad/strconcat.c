#include "mystrings.h"
#include <stdio.h>

int main(int argc, char **argv){
    if(argc != 3){
        printf("Error: in input");
    }

    char* firstString = argv[1];
    char* secondString = argv[2];
    if(strlength(firstString) >= 50 || strlength(secondString) >= 50){
        printf("Smaller strings");
    }
    strconcat(firstString, secondString);
    printf("The contracted string is - %s", firstString);
    return 0;
}

