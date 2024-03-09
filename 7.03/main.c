#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeSubjects(char** subjects, int numSubjects) {
    for (int i = 0; i < numSubjects; ++i) {
        free(subjects[i]);
    }
    free(subjects);
}

void freeGrades(int** grades, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        free(grades[i]);
    }
    free(grades);
}

void freeStudents(char** students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        free(students[i]);
    }
    free(students);
}

int main() {
    int numSubjects, choice;

    do
    {
        printf("Enter the positive number of subjects: ");
        scanf("%d", &numSubjects);
    }
    while (numSubjects <= 0);

    char** subjects = (char**)malloc(numSubjects * sizeof(char*));
    for (int i = 0; i < numSubjects; ++i) {
        subjects[i] = (char*)malloc(16 * sizeof(char));
        printf("Enter the name of subject: ");
        scanf("%s", subjects[i]);
    }

    char** students = NULL;
    int numStudents = 0;
    int** grades = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Add student\n");
        printf("2. Print diary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char* name = (char*)malloc(16 * sizeof(char));
                printf("Enter student name: ");
                scanf("%s", name);

                students = (char**)realloc(students, (numStudents + 1) * sizeof(char*));
                students[numStudents] = name;

                grades = (int**)realloc(grades, (numStudents + 1) * sizeof(int*));
                grades[numStudents] = (int*)malloc(numSubjects * sizeof(int));

                for (int i = 0; i < numSubjects; ++i) {
                    printf("Enter grade for %s in %s: ", name, subjects[i]);
                    scanf("%d", &grades[numStudents][i]);
                }

                ++numStudents;
                break;
            }
            case 2: {
                printf("%-15s", "");
                for (int i = 0; i < numSubjects; ++i) {
                    printf("%-10s", subjects[i]);
                }
                printf("\n");

                for (int i = 0; i < numStudents; ++i) {
                    printf("%-15s", students[i]);
                    for (int j = 0; j < numSubjects; ++j) {
                        printf("%-10d", grades[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                freeSubjects(subjects, numSubjects);
                freeGrades(grades, numStudents);
                freeStudents(students, numStudents);
                break;
            }
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}