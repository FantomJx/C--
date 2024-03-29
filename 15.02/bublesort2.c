#include <stdio.h>

int compare(void *a, void *b);
void swapelements(void *a, void *b);

void bubbleSort(int arr[], int n, int (*compare)(const void*, const void*), void (*swapelements)(void*, void*))
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

void int_swap(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;

    int temp = *int_a;
    *int_a = *int_b;
    *int_b = temp;
}

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

    int arr[] = { 64, 20, 1, 12, 5, 11, 94390 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n, compareasc, int_swap);
    printf(" 1 Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n, comparedesk, int_swap);
    printf("\n2 Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}