#include <stdio.h>

void swap(void * a, void * b) {

    int *pointer_a = (int *)a;
    int *pointer_b = (int *)b;

    int temp = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = temp;
}

int main() {

  int a = 7;
  int b = 5;
  swap(&a, &b);
  
  printf("A:%d, B:%d\n", a, b);

  return 0;
}