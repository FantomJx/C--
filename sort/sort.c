#include <stdio.h>

#define SWAP(n1, n2, type) do { \
    type temp = n1; \
    n1 = n2; \
    n2 = temp; \
} while (0)

#define SORT(arr, n, type, comp) do { \
    for (int i = 0; i < n - 1; i++) { \
        for (int j = 0; j < n - i - 1; j++) { \
            if (arr[j] comp arr[j+1]) { \
                SWAP(arr[j], arr[j+1], type); \
            } \
        } \
    } \
} while (0)

int main() {
    int asc_arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(asc_arr) / sizeof(asc_arr[0]);

    SORT(asc_arr, size, int, >);

    printf("After sorting in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", asc_arr[i]);
    }
    printf("\n");
    
    int des_arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size = sizeof(des_arr) / sizeof(des_arr[0]);

    SORT(des_arr, size, int, <);

    printf("After sorting in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", des_arr[i]);
    }
    return 0;
}
