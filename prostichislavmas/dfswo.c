#include <stdio.h>

#define max 100

int main() {
    int A[max], n, br = 0, sum = 0;
    printf("Size of array: ");
    scanf("%d", &n);
    printf("Numbers for array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= A[i]; j++) {
            if (A[i] % j == 0) br++;
        }
        if (br == 2) sum = sum + A[i];
        br=0;
    }
    printf("Sum is: %d", sum);
    return 0;
}