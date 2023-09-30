#include <stdio.h>

#define max 100


void bubbleSort(int A[], int n) {
    int b;
    int sw;
    for (int i = 0; i < n - 1; i++) {
        sw = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                b = A[j];
                A[j] = A[j + 1];
                A[j + 1] = b;
                sw = 1;
            }
        }
        if (sw == 0)
            break;
    }
}

int binarySearch(int A[], int l, int r, int targ) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (A[mid] == targ)
            return mid;

        if (A[mid] < targ)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    int A[max], n, targ;
    printf("Size of array: ");
    scanf("%d", &n);
    printf("Numbers for array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Target: ");
    scanf("%d", &targ);
    bubbleSort(A, n);
    printf("%d", binarySearch(A, 0, n - 1, targ));
    return 0;
}