#include <stdio.h>


void dvoich(long n) {
    if (n > 0) {
        dvoich(n / 2);
        printf("%ld", n % 2);
    }
}


int main(){
    int n;
    printf("Number: ");
    scanf("%d", &n);
    dvoich(n);
    return 0;
}