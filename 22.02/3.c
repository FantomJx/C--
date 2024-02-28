#include<stdio.h>
#include<string.h>

void strhalf(char *str, char **half) {
    int length = strlen(str);
    *half = str + length / 2;
}

int main()
{
    char arr[] = "Ivan";

    char *half;
    strhalf(arr, &half);
    printf("Second half: %s\n", half);

    return 0;
}