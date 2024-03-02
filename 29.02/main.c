#include <stdio.h>
#include <stdlib.h>

#define ERROR_MESSAGE 1

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Average grade\n");
    printf("2. New grade\n");
    printf("3. Delete grade\n");
    printf("4. Exit\n");
}

int main() {
    int* grades;
    int numGrades = 0;
    int choice;
    int sum = 0;
    
    printf("Enter number of grades: ");
    scanf("%d", &numGrades);

    if (numGrades <= 0) {
        printf("Number of grades has to be more than 0!\n");
        return 1;
    }

    grades = (int *)malloc(numGrades * sizeof(int));
    if (!grades) {
        printf("Error\n");
        return 1;
    }

    printf("Enter grades:\n");
    for (int i = 0; i < numGrades; ++i) {
        scanf("%d", &grades[i]);
    }

    do {
        printMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                for (int i = 0; i < numGrades; ++i) {
                    sum += grades[i];
                }
                float average = (float)sum / numGrades;
                printf("Average: %.2f\n", average);
                break;
            case 2: {
                int newGrade;
                printf("Enter grade: ");
                scanf("%d", &newGrade);
                
                int* temp = (int*)realloc(grades, (numGrades + 1) * sizeof(int));
                if (temp == NULL) {
                    printf("Error\n");
                    exit(ERROR_MESSAGE);
                }
                grades = temp;
                grades[numGrades] = newGrade;
                numGrades++;
                break;
            }
            case 3:
                if (numGrades == 0) {
                    printf("No grades to be deleted\n");
                } else {
                    numGrades--;
                    int* temp = (int*)realloc(grades, numGrades * sizeof(int));
                    if (temp == NULL && numGrades > 0) {
                        printf("Error\n");
                        exit(ERROR_MESSAGE);
                    }
                    grades = temp;
                }
                break;
            case 4:
                free(grades);
                printf("Exit\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}
