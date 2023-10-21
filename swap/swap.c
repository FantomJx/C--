#include <stdio.h>

#define sw(n1, n2, type) do { \
    type temp = n1; \
    n1 = n2; \
    n2 = temp; \
} while (0)

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    sw(a, b, int);
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}