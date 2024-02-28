#include <stdio.h>

int compare(void *a, void *b);
void swapelements(void *a, void *b);

void bubbleSort(int arr[], int n, int (*compare)(void*, void*), void (*swapelements)(void*, void*))
{
    int i, j;
    int swapped = 0;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if(compare(&arr[j], &arr[j + 1]) > 0) {
                swapelements(arr + j, arr + j + 1);
                swapped = 1;
            }

        }
 
        if (swapped == 0)
            break;
    }
}

int descending_compare(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;

    return *int_b - *int_a;
}

int ascending_compare(void *a, void *b) {
    
    int *int_a = (int *)a;
    int *int_b = (int *)b;

    return *int_a - *int_b;
}

void int_swap(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;

    int temp = *int_a;
    *int_a = *int_b;
    *int_b = temp;
}


int main(){

    int arr[] = { 64, 20, 1, 12, 5, 11, 94390 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n, descending_compare, int_swap);
    printf("1 Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n, ascending_compare, int_swap);
    printf("\n2 Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}