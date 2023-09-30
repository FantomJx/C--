#include <stdio.h>
#include <string.h>
#define max 100

int main(){
    char A[max], maxch = 0;
    printf("Enter a string: ");
    scanf("%s", A);

    for (int i = 0; i < strlen(A); i++) {
        if(A[i] > maxch) maxch = A[i];
    }
    printf("Max char is: %c", maxch);
    return 0;
}