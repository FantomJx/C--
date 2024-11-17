#include <stdio.h>
#include <stdlib.h>
// Аз го направих с последната, защото може да го делим само веднъж

void printArray(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int mDigit(int* arr, int count) {
    int max = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int digits = 0;
    while (max != 0) {
        max /= 10;
        digits++;
    }
    return digits;
}

int get(int number, int digitInd) {
    for (int i = 0; i < digitInd; i++) {
        number /= 10;
    }
    return number % 10;
}

void radix_sort(int* arr, int count, int digitInd) {
    if (count <= 1 || digitInd < 0) {
        return;
    }

    int* bucket[10];
    int buckCount[10] = {0};

    for (int i = 0; i < 10; i++) {
        bucket[i] = (int*)malloc(count * sizeof(int));
    }

    for (int i = 0; i < count; i++) {
        int digit = get(arr[i], digitInd);
        bucket[digit][buckCount[digit]++] = arr[i];
    }

    int ind = 0;
    for (int i = 0; i < 10; i++) {
        if (buckCount[i] > 0) {
            radix_sort(bucket[i], buckCount[i], digitInd - 1);
            for (int j = 0; j < buckCount[i]; j++) {
                arr[ind++] = bucket[i][j];
            }
        }
        free(bucket[i]);
    }
    printf("Sort by position digit %d:\n", digitInd + 1);
    printArray(arr, count);
}

int main() {
    int arr1[] = {5, 23, 45, 43, 10, 22, 55, 155, 125};
    int arr2[] = {12 ,889, 163, 8, 0, 12};
    int arr3[] = {985, 745, 745, 845, 213, 79, 782, 857, 964, 535, 784, 951, 425, 0, 45};
    int count = sizeof(arr1) / sizeof(arr1[0]);
    int count2 = sizeof(arr2) / sizeof(arr2[0]);
    int count3 = sizeof(arr3) / sizeof(arr3[0]);


    printf("Array:\n");
    printArray(arr1, count);

    int maxDigits = mDigit(arr1, count);
    radix_sort(arr1, count, maxDigits - 1);

    printf("Sorted:\n");
    printArray(arr1, count);


    printf("\n\nArray:\n");
    printArray(arr2, count2);

    maxDigits = mDigit(arr2, count2);
    radix_sort(arr2, count2, maxDigits - 1);

    printf("Sorted:\n");
    printArray(arr2, count2);
    printf("\n\nArray:\n");
    printArray(arr3, count3);

    maxDigits = mDigit(arr3, count3);
    radix_sort(arr3, count3, maxDigits - 1);

    printf("Sorted:\n");
    printArray(arr3, count3);

    return 0;
}
