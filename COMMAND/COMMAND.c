#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _command

#define DEFINE_COMMAND(NAME, TYPE) \
    void TYPE ## _ ## NAME ## _command(void)

DEFINE_COMMAND(q, extr) {
    printf("External quit command\n");
}

DEFINE_COMMAND(h, intr) {
    printf("Internal help command\n");
}

int main() {
    extr_q_command();
    intr_h_command();
    return 0;
}