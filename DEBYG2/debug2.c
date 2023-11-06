#include <stdio.h>
#define DEBUG


int sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int sw = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
                sw = 1;
            }
        }
        if (sw == 0)
            break;
    }
#ifdef DEBUG
    printf("Sorted array: ");
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nElements on Indexes / 3: ");
    for(int i = 0; i< n; i+=3){
        printf("%d ", arr[i]);
    }
#else
    printf("DEBUG is not defined");
#endif
    int sum = 0;
    for(int i = 0; i < n; i+=3) {
        sum += arr[i];
    }
    return sum;
}

int main(){
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = 11;
    printf("\n%d", sort(arr, size));
    return 0;
}