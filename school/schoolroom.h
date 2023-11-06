#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H
#include "person.h"

typedef struct Schoolroom{
    int room_numb;
    Person people[50];
} Schoolroom;

#endif