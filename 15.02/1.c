#include <stdio.h>

int main() {

  double a, b;
  scanf("%lf", &a);
  scanf("%lf", &b);
  
  printf("Address of a: %p\n", &a);
  printf("Address of b: %p\n", &b);

  double * p = &a;
  printf("Value of a: %lf\n", *p);

  *p = b;
  printf("Value of b: %lf\n", *p);



  return 0;
}