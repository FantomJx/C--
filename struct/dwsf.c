#include <stdio.h>

struct student{
    char name[20];
    int number;
    float uspeh;
};

int main(){
    struct student s1;

    printf("Student's name: ");
    scanf("%s", s1.name);
    printf("Student's number: ");
    scanf("%d", &s1.number);
    printf("Student's uspeh: ");
    scanf("%f", &s1.uspeh);

    printf("Name: %s \n", s1.name);
    printf("Number: %d \n", s1.number);
    printf("Uspeh: %f \n", s1.uspeh);
    return 0;
}