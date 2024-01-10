#include "transformation.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Transformation int_from_char(char *str)
{
    Transformation tmp;
    char* endptr;

    tmp.result = strtol(str, &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n') {
        tmp.result = 0;
        snprintf(tmp.error, 100, "Invalid input string");
    } else {
        tmp.error[0] = '\0';
    }

    return tmp;
}
