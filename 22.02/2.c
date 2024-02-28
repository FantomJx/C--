#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

int main()
{
    int arr[] = {21, 43, 53, 12, 443, 1, 24, -34, 4, 0};

    sort(arr, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}