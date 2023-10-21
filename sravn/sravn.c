#include <stdio.h>
#define srv(n1, n2) ((n1 > n2) ? n1 : n2)

int main() {
    int a = 2;
    int b = 5;
    int res = srv(a, b);
    printf("Bigger is: %d\n", res);
    return 0;
}