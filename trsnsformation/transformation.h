#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

typedef struct {
    long result;
    char error[100];
} Transformation;

Transformation int_from_char(char *str);

#endif
