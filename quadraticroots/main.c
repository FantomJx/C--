#include <stdio.h>
#include "quadraticroots.h"

int main() {
    QuadraticRootsResult result1 = findroots(1, 2, 1);
    QuadraticRootsResult result2 = findroots(1.5, 3.6, 2.1);
    QuadraticRootsResult result3 = findroots(2.5, 2.8, 1.2);

    printf("First result: x1 = %f, x2 = %f, norealroots = %d\n", result1.x1, result1.x2, result1.norealroots);
    printf("Second result: x1 = %f, x2 = %f, norealroots = %d\n", result2.x1, result2.x2, result2.norealroots);
    printf("Third result: x1 = %f, x2 = %f, norealroots = %d\n", result3.x1, result3.x2, result3.norealroots);

    return 0;
}
