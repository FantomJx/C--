#include "processes.h"
#include <stdio.h>

void printallprocesses() {
    printf("Processes:\n");
    for (int i = 0; i < processescount; i++) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH + 1];
    int processid;

    do {
        printf("1. New process\n");
        printf("2. All processes\n");
        printf("3. Stop process\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                int id = createnewprocess(name);
                if (id != 0) {
                    printf("Created with ID: %d\n", id);
                }
                break;
            case 2:
                printallprocesses();
                break;
            case 3:
                printf("Enter ID to stop: ");
                scanf("%d", &processid);
                stopprocess(processid);
                break;
            case 4:
                printf("Exiting...\n");
                break;

            printf("Error\n");
        }
    } while (choice != 4);

    return 0;
}
