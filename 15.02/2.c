#include <stdio.h>
#include <string.h>

int main() {
    char str[250];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    char *newline = strchr(str, '\n');

    if (newline != NULL) { 
        *newline = '\0';
    }

    printf("New string%s\n", str);

    return 0;
}
