#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LENGTH 100

typedef struct Worker {
    char name[NAME_MAX_LENGTH];
    int num_subordinates;
    struct Worker **subordinates;
} Worker;

Worker* create_worker(const char *name, int num_subordinates);
void add_subordinate(Worker *manager, Worker *subordinate);
void free_worker(Worker *worker);
void serialize_worker(FILE *file, Worker *worker);
Worker* deserialize_worker(FILE *file);
void print_worker(Worker *worker, int level);

int main() {
    Worker *director = create_worker("Director", 2);
    Worker *manager1 = create_worker("Manager 1", 2);
    Worker *manager2 = create_worker("Manager 2", 2);

    add_subordinate(director, manager1);
    add_subordinate(director, manager2);

    add_subordinate(manager1, create_worker("Worker 1", 0));
    add_subordinate(manager1, create_worker("Worker 2", 0));

    add_subordinate(manager2, create_worker("Worker 4", 0));
    add_subordinate(manager2, create_worker("Worker 5", 0));

    FILE *file = fopen("main.bin", "wb");
    if (!file) {
        return 1;
    }

    serialize_worker(file, director);
    fclose(file);

    free_worker(director);

    file = fopen("main.bin", "rb");
    if (!file) {
        return 1;
    }

    Worker *deserialized_director = deserialize_worker(file);
    fclose(file);

    print_worker(deserialized_director, 0);

    free_worker(deserialized_director);

    return 0;
}

Worker* create_worker(const char *name, int num_subordinates) {
    Worker *worker = (Worker *)malloc(sizeof(Worker));
    if (!worker) {
        exit(1);
    }

    strncpy(worker->name, name, NAME_MAX_LENGTH);
    worker->name[NAME_MAX_LENGTH - 1] = '\0';

    worker->num_subordinates = num_subordinates;
    if (num_subordinates > 0) {
        worker->subordinates = (Worker **)malloc(num_subordinates * sizeof(Worker *));
        if (!worker->subordinates) {
            free(worker);
            exit(1);
        }
    } else {
        worker->subordinates = NULL;
    }
    return worker;
}

void add_subordinate(Worker *manager, Worker *subordinate) {
    static int index = 0;
    if (index < manager->num_subordinates) {
        manager->subordinates[index++] = subordinate;
    }
    if (index == manager->num_subordinates) {
        index = 0;
    }
}

void serialize_worker(FILE *file, Worker *worker) {
    if (!file || !worker) {
        return;
    }
    fwrite(worker->name, sizeof(char), NAME_MAX_LENGTH, file);
    fwrite(&worker->num_subordinates, sizeof(int), 1, file);
    for (int i = 0; i < worker->num_subordinates; i++) {
        serialize_worker(file, worker->subordinates[i]);
    }
}

Worker* deserialize_worker(FILE *file) {
    if (!file) {
        return NULL;
    }

    Worker *worker = (Worker *)malloc(sizeof(Worker));
    if (!worker) {
        exit(1);
    }

    fread(worker->name, sizeof(char), NAME_MAX_LENGTH, file);
    fread(&worker->num_subordinates, sizeof(int), 1, file);

    if (worker->num_subordinates > 0) {
        worker->subordinates = (Worker **)malloc(worker->num_subordinates * sizeof(Worker *));
        if (!worker->subordinates) {
            free(worker);
            exit(1);
        }
        for (int i = 0; i < worker->num_subordinates; i++) {
            worker->subordinates[i] = deserialize_worker(file);
        }
    } else {
        worker->subordinates = NULL;
    }

    return worker;
}

void print_worker(Worker *worker, int level) {
    if (!worker) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%s\n", worker->name);
    for (int i = 0; i < worker->num_subordinates; i++) {
        print_worker(worker->subordinates[i], level + 1);
    }
}

void free_worker(Worker *worker) {
    if (!worker) {
        return;
    }
    for (int i = 0; i < worker->num_subordinates; i++) {
        free_worker(worker->subordinates[i]);
    }
    free(worker->subordinates);
    free(worker);
}
