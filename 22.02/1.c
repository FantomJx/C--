#include<stdio.h>

int strlength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main()
{
    char arr[] = "Ivan";

    printf("%d\n", strlength(arr));

    return 0;
}