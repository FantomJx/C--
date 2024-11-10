#include <stdio.h>

union OddEven {
    long odd;
    short even;
};

int main() {
    union OddEven arr[10];

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            arr[i].even = i;
        } else {
            arr[i].odd = i;
        }
    }

    printf("Нечетни индекси:\n");
    for (int i = 1; i < 10; i += 2) {
        printf("%ld\n", arr[i].odd);
    }

    printf("Четни индекси:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("%d\n", arr[i].even);
    }

    return 0;
}