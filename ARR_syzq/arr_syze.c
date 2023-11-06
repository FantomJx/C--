#include <stdio.h>
#include <math.h>
#define ARR_SIZE 5

int main(){
    int arr[ARR_SIZE];
#ifdef ARR_SIZE
    int n = 0;
    for(int i = 0; i < ARR_SIZE; i++){
        arr[i] = (int)pow(2, n);
        n++;
    }
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("\n%d", arr[i]);
    }
#endif
    return 0;
}