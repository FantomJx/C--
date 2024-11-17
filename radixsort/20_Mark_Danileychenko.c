#include <stdio.h>
#include <stdlib.h>


void printArray(int* arr, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция за намиране на максималния брой цифри в масива
int getMaxDigits(int* arr, unsigned int count) {
    int max = arr[0];
    for (unsigned int i = 1; i < count; i++) {
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

int getDigit(int number, int digitIndex) {
    for (int i = 0; i < digitIndex; i++) {
        number /= 10;
    }
    return number % 10;
}

void radix_sort(int* arr, unsigned int count, int digitIndex) {
    if (count <= 1 || digitIndex < 0) {
        return;
    }

    printf("Сортиране по цифра на позиция %d:\n", digitIndex);
    printArray(arr, count);

    // Създаване на кофички за всяка цифра от 0 до 9
    int* buckets[10];
    int bucketCounts[10] = {0};

    for (int i = 0; i < 10; i++) {
        buckets[i] = (int*)malloc(count * sizeof(int));
    }

    // Разпределяне на елементите в кофички според текущата цифра
    for (unsigned int i = 0; i < count; i++) {
        int digit = getDigit(arr[i], digitIndex);
        buckets[digit][bucketCounts[digit]++] = arr[i];
    }

    // Рекурсивно сортиране на всяка кофичка и обединяване обратно
    int index = 0;
    for (int i = 0; i < 10; i++) {
        if (bucketCounts[i] > 0) {
            radix_sort(buckets[i], bucketCounts[i], digitIndex - 1);
            for (int j = 0; j < bucketCounts[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
        free(buckets[i]);
    }
}

int main() {
    int arr1[] = {5, 23, 45, 43, 10, 22, 55, 155, 125};
    unsigned int count1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Начален масив:\n");
    printArray(arr1, count1);

    int maxDigits = getMaxDigits(arr1, count1);
    radix_sort(arr1, count1, maxDigits - 1);

    printf("Сортиран масив:\n");
    printArray(arr1, count1);

    return 0;
}
