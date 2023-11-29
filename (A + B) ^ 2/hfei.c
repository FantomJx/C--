#include <stdio.h>
#define MACRO(A, B) ((A + B) * (A + B))

int main(){
    int a = 2, b = 1;
    printf("%d", MACRO(a, b));
    return 0;
}