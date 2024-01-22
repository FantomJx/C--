#include "processes.h"
#include <stdio.h>
#include <string.h>

Process processes[MAX_PROCESSES];
int processescount = 0;

static int isvalidid(int id) {
    return id > 0 && id <= MAX_PROCESSES;
}

int nextprocessid() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].id == 0) {
            processes[i].id = i + 1;
            return processes[i].id;
        }
    }
    return 0;
}

int createnewprocess(char *name) {
    if (processescount < MAX_PROCESSES) {
        int id = nextprocessid();
        if (id != 0) {
            strncpy(processes[processescount].name, name, MAX_NAME_LENGTH);
            processes[processescount].name[MAX_NAME_LENGTH] = '\0';
            processescount++;
        }
        return id;
    } else {
        printf("Error.\n");
        return 0;
    }
}

void stopprocess(int processid) {
    if (isvalidid(processid)) {
        for (int i = 0; i < processescount; i++) {
            if (processes[i].id == processid) {
                // Move the last process to the empty slot
                processes[i] = processes[processescount - 1];
                processes[processescount - 1].id = 0;
                processescount--;
                printf("Process %d stopped.\n", processid);
                return;
            }
        }
    } else {
        printf("Error: Invalid process ID.\n");
    }
}
