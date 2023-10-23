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
    int f_arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = 10;

    SORT(f_arr, size, int, >);

    printf("After sorting in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", f_arr[i]);
    }
    printf("\n");

    int s_arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size = 10;

    SORT(s_arr, size, int, <);

    printf("After sorting in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", s_arr[i]);
    }
    return 0;
}
