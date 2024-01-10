#include <stdio.h>
#include <math.h>

void pow_arr(long arr[], int size)
{
    for(int i = 0; i < size; i++){
        arr[i] = pow(arr[i], 4);
    }
}

int main(){
    long numb[] = {1, 2, 3, 4};
    int size = 4;
    pow_arr(numb, size);

    for(int i = 0; i < size; i++){
        printf("%ld ", numb[i]);
    }

    return 0;
}