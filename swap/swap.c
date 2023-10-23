#include <stdio.h>

#define sw(n1, n2, type) do{ \
    type n3 = n1; \
    n1 = n2; \
    n2 = n3;  \
    }while(0)

int main() {
    char a = 'f';
    char b = 'd';
    printf("Before swap: a = %c, b = %c\n", a, b);
    sw(a, b, char);
    printf("After swap: a = %c, b = %c\n", a, b);

    int c = 7, d = 10;
    printf("Before swap: a = %d, b = %d\n", c, d);
    sw(c, d, int);
    printf("After swap: a = %d, b = %d\n", c, d);
    return 0;
}