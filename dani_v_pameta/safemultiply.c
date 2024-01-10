#include "safeint.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Неправилен брой аргументи");
        return 1;
    }

    struct SafeResult a = safestrtoint(argv[1]);
    struct SafeResult b = safestrtoint(argv[2]);

    struct SafeResult result = safemultiply(a.value, b.value);

    if (result.errorflag) {
        printf("Аргументи надвишават стойности");

        return 1;
    }

    printf("Произведението на %d и %d е %d\n", a.value, b.value, result.value);

    return 0;
}