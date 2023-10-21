#include <stdio.h>

#define DEBUG_PRINT(n) \
    printf("Debug Info: %s = %d (File: %s, Line: %d)\n", #n, n, __FILE__, __LINE__); \

int main() {
    int x = 42;
    DEBUG_PRINT(x);
    return 0;
}