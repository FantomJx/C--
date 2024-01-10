#include <stdio.h>
#include "mystrings.h"

int strlength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void strconcat(char* str1, char* str2) {
    int i = 0;
    int j = 0;

    while (str1[i] != '\0') {
        i++;
    }

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';
}

int strcompare(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 < *str2) {
        return -1;
    } else if (*str1 > *str2) {
        return 1;
    } else {
        return 0;
    }
}

int main()
    {
        char str1[] = "Hello";
        char str2[] = "World";

        int length = strlength(str1);
        printf("Len is: %d\n", length);

        strconcat(str1, str2);
        printf("Result: %s\n", str1);

        int res = strcompare("Alex", "Alan");
        printf("Comparison result for 'Alex' and 'Alan': %d\n", res);

        res = strcompare("Alex", "Alex");
        printf("%d\n", res);

        res = strcompare("Alex", "Boyan");
        printf("%d\n", res);

        return 0;
    }
