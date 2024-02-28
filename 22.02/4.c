#include<stdio.h>
#define COLS 4



void printTable(int *arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", *(arr + i * COLS + j));
        }
        printf("\n");
    }
}

int main()
{
    int table[3][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printTable((int *)table, 3);

    return 0;
}