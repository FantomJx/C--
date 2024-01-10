#include "mystrings.h"

int strlength(char* string)
{
    int result = 0;
    for(int i=0; string[i] != '\0'; i++) {
        result ++;
    }
    return result;
}
void strconcat(char* string1, char* string2)
{
    int i = 0;
    int j = strlength(string1);
    while (string2[i] != '\0') {
        string1[j] = string2[i];
        i++;
        j++;
    }
    string1[j] = '\0';
}
int strcompare(char* string1, char* string2)
{
    int i = 0;
    while(string1[i] != '\0' && string2[i] != '\0'){
        if(string1[i] < string2[i]){
            return -1;
        }else if(string1[i] > string2[i]){
            return 1;
        }
        i++;
    }
    if(string1[i] == '\0' && string2[i] == '\0'){
        return 0;
    }else if(string1[i] == '\0'){
        return -1;
    }else{
        return 1;
    }
}