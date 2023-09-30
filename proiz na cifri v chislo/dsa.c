#include <stdio.h>

int main(){
    int n, proizv=1;
    printf("Number: ");
    scanf("%d", &n);
    while(n!=0) {
        int b = n%10;
        proizv=proizv*b;
        n=n/10;
    }
    printf("Proizv is: %d", proizv);
    return 0;
}
