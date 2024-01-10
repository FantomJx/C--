#include "safeint.h"
#include <stdlib.h>
#include <limits.h>

struct SafeResult safeadd(int a, int b){
    struct SafeResult result;
    result.value = a + b;

    if(result.value < a)
    {
        result.errorflag = 1;
    }
    else
    {
        result.errorflag = 0;
    }
    return result;
}

struct SafeResult safesubtract(int a, int b){
    struct SafeResult result;
    result.value = a - b;
    if(result.value > a)
    {
        result.errorflag = 1;
    }
    else
    {
        result.errorflag = 0;
    }
    return result;
}

struct SafeResult safemultiply(int a, int b){
    struct SafeResult result;
    result.value = a * b;
    if(result.value / a != b)
    {
        result.errorflag = 1;
    }
    else
    {
        result.errorflag = 0;
    }
    return result;
}
struct SafeResult safedivide(int a, int b) {
    struct SafeResult result;
    result.value = a / b;

    if (b == 0) {
        result.errorflag = 1;
    } else {
        result.errorflag = 0;
    }

    return result;
}

struct SafeResult safestrtoint(const char* str) {
    struct SafeResult result;

    int value = atoi(str);

    if (value < INT_MIN || value > INT_MAX) {
        result.value = 0;
        result.errorflag = 1;
    } else {
        result.value = value;
        result.errorflag = 0;
    }

    return result;
}