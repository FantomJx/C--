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

int main() {
    int A[max], sum, n;
    printf("Size of array: ");
    scanf("%d", &n);
    printf("Numbers for array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    bubbleSort(A, n);
    for (int i = 0; i < n; i++) {
        int b = A[i] * i;
        sum += b;
    }
    printf("Sum is: %d", sum);
    return 0;

}
