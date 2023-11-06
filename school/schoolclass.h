#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

typedef struct Schoolclass{
    Person students[26];
    char parallel;
    int class_number;
    Person class_teacher;
} Schoolclass;
#endif
