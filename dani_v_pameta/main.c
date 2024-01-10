#include <stdio.h>
#include <limits.h>

#define PRINT_INT_INFO(type) \
    printf("Type: %s\t| Format: %s\t| Size (bytes): %zu\t", #type, \
            sizeof(type) == 1 ? "%hhd" : sizeof(type) == 2 ? "%hd" : sizeof(type) == 4 ? "%d" : sizeof(type) == 8 ? "%ld" : "Unknown", sizeof(type)); \
    printf("Signed: Max = %d, Min = %d\t", INT_MAX, INT_MIN); \
    printf("Unsigned: Format: %s\t| Max = %u\n\n", sizeof(type) == 1 ? "%hhu" : sizeof(type) == 2 ? "%hu" : sizeof(type) == 4 ? "%u" : sizeof(type) == 8 ? "%lu" : "Unknown", UINT_MAX);

int main() {
    printf("Information for Integer Types in C:\n\n");

    PRINT_INT_INFO(char);
    PRINT_INT_INFO(short);
    PRINT_INT_INFO(int);
    PRINT_INT_INFO(long);
    PRINT_INT_INFO(long long);

    return 0;
}
