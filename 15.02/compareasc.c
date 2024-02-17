#include <stdio.h>

int compareasc(const void *a, const void *b)
{
    int *pointer_a = (int *)a;
    int *pointer_b = (int *)b;
    if(*pointer_a > *pointer_b) return 1;
    if(*pointer_a < *pointer_b) return -1;
    return 0;
}

int comparedesk(const void *a, const void *b)
{
    const int *pointer_a = (int *)a;
    const int *pointer_b = (int *)b;
    if(*pointer_a < *pointer_b) return 1;
    if(*pointer_a > *pointer_b) return -1;
    return 0;
}


int main(){

    const int a = 100;
    const int b = 98;

    printf("Result: %d\n", compareasc(&a, &b));
    printf("Result2: %d\n", comparedesk(&a, &b));

    return 0;
}