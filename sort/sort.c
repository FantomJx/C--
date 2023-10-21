#include <stdio.h>

#define SWAP(n1, n2, type) do { \
    type temp = n1; \
    n1 = n2; \
    n2 = temp; \
} while (0)

#define SORT(arr, n, type, comp) do { \
    for (int i = 0; i < n - 1; i++) { \
        for (int j = 0; j < n - i - 1; j++) { \
            if (comp(arr[j], arr[j+1])) { \
                SWAP(arr[j], arr[j+1], type); \
            } \
        } \
    } \
} while (0)

int main() {
    int ascending_array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(ascending_array) / sizeof(ascending_array[0]);
    SORT(ascending_array, size, int, >);
    printf("After sorting in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ascending_array[i]);
    }
    printf("\n");
    int des_arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size = sizeof(des_arr) / sizeof(des_arr[0]);
    SORT(des_arr, size, int, <);
    printf("After sorting in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", des_arr[i]);
    }
    printf("\n");
    return 0;
}
