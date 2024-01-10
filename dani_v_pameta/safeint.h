#ifndef DANI_V_PAMETA_SAFEINT_H
#define DANI_V_PAMETA_SAFEINT_H

#include <stdio.h>

struct SafeResult{
    int value;
    char errorflag;
};

struct SafeResult safeadd(int a, int b);
struct SafeResult safesubtract(int a, int b);
struct SafeResult safemultiply(int a, int b);
struct SafeResult safedivide(int a, int b);
struct SafeResult safestrtoint(const char* str);


#endif