#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    char name[16];
    int classNumber;
    double averageGrade;
};

void addStudent(struct Student** students, int* count) {
    char name[16];
    int classNumber;
    double averageGrade;

    printf("Name: ");
    scanf("%s", name);

    printf("Class number: ");
    scanf("%d", &classNumber);

    printf("Average grade: ");
    scanf("%lf", &averageGrade);

    if (*count == 0) {
        *students = (struct Student*)malloc(sizeof(struct Student));
    } else {
        *students = (struct Student*)realloc(*students, (*count + 1) * sizeof(struct Student));
    }

    if (*students == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy((*students)[*count].name, name);
    (*students)[*count].classNumber = classNumber;
    (*students)[*count].averageGrade = averageGrade;
    ++(*count);

    printf("Student added successfully.\n");
}

void displayStudents(const struct Student* students, int count) {
    printf("Students:\n");
    for (int i = 0; i < count; ++i) {
        printf("Name: %s, Class Number: %d, Average Grade: %.2f\n",
               students[i].name, students[i].classNumber, students[i].averageGrade);
    }
}

int main() {
    struct Student* students;
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n1. Add student\n2. All students\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &count);
                break;
            case 2:
                if (count == 0) {
                    printf("No students.\n");
                } else {
                    displayStudents(students, count);
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    free(students);
    return 0;
}
