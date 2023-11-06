#include <stdio.h>
#include "schoolroom.h"
#include "schoolclass.h"

typedef struct School{
     Schoolclass class[20];
     Schoolclass rooms[10];
} School;

int main(){
    School school;
    Schoolclass class = {
            .students = {
                    {
                            .name = "FWMI",
                            .surname = "weni",
                            .lastname = "wcjwi",
                            .year_of_birth = 2000,
                    },
            },
            .parallel = 'A',
            .class_number = 1,
            .class_teacher = {
                    .name = "ncwdo",
                    .surname = "cenw",
                    .lastname = "fnwje",
                    .year_of_birth = 1980,
            },
    };
    school.class[0] = class;
    return 0;
}