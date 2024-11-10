#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "file.bin"
#define NAME_MAX_LENGTH 255

typedef struct {
    char egn[11];
    char name[NAME_MAX_LENGTH + 1];
    int age;
    int details[3];
} Citizen;


void new_citizen() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        exit(1);
    }

    Citizen citizen;

    printf("EGN: ");
    fgets(citizen.egn, 11, stdin);
    getchar();

    printf("Name: ");
    fgets(citizen.name, NAME_MAX_LENGTH, stdin);
    citizen.name[strcspn(citizen.name, "\n")] = 0;

    printf("Age: ");
    scanf("%d", &citizen.age);
    getchar();

    printf("Education (0: No education, 1: Primary, 2: Secondary, 3: Higher): ");
    scanf("%d", &citizen.details[0]);
    getchar();

    printf("Work Status (0: Unemployed, 1: Employed): ");
    scanf("%d", &citizen.details[1]);
    getchar();

    printf("Marital Status (0: Single, 1: Married): ");
    scanf("%d", &citizen.details[2]);
    getchar();


    fwrite(&citizen, sizeof(Citizen), 1, file);
    fclose(file);
}

void delete_record() {
    char egn[11];
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *tempFile = fopen("t.bin", "wb");

    if (!file || !tempFile) {
        exit(1);
    }

    printf("Enter EGN to delete: ");
    fgets(egn, 11, stdin);
    getchar();

    Citizen citizen;
    int found = 0;
    while (fread(&citizen, sizeof(Citizen), 1, file)) {
        if (strncmp(citizen.egn, egn, 10) != 0) {
            fwrite(&citizen, sizeof(Citizen), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("t.bin", FILE_NAME);

    if (found) {
        printf("Citizen deleted successfully.\n");
    } else {
        printf("Citizen not found.\n");
    }
}

void print_citizens() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        exit(1);
    }

    Citizen citizen;
    unsigned char education, work_status, marital_status;
    while (fread(&citizen, sizeof(Citizen), 1, file)) {
        printf("EGN: %s\n", citizen.egn);
        printf("Name: %s\n", citizen.name);
        printf("Age: %d\n", citizen.age);
        printf("Education: %u\n", citizen.details[0]);
        printf("Work Status: %u\n", citizen.details[1]);
        printf("Marital Status: %u\n\n", citizen.details[2]);
    }

    fclose(file);
}

int main() {
    int choice;

    FILE *file = fopen(FILE_NAME, "ab+");
    if (!file) {
        exit(1);
    }

    while (1) {
        printf("1. New citizen\n");
        printf("2. Delete citizen by EGN\n");
        printf("3. Print all citizens\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                new_citizen();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                print_citizens();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
