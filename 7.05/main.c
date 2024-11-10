#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum State {
    NEW,
    IN_PROGRESS,
    COMPLETED
};

typedef struct task {
    int priority;
    char description[100];
    enum State state;
}Task;

typedef struct node {
    Task task;
    struct node* next;
}Node;

void addTask(Node** head, int priority, const char* description) {
    Task newTask;
    newTask.priority = priority;
    strcpy(newTask.description, description);
    newTask.state = NEW;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL || priority < (*head)->task.priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->task.priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void changeState(Node *head, int priority, enum State new_state) {
    Node *current = head;
    while (current != NULL) {
        if (current->task.priority == priority) {
            current->task.state = new_state;
            return;
        }
        current = current->next;
    }
}

void displayTasks(Node* head) {
    printf("Tasks:\n");
    while (head != NULL) {
        printf("Priority: %d, Description: %s, State: %d\n", head->task.priority, head->task.description, head->task.state);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    addTask(&head, 1, "Wash the dishes");
    addTask(&head, 2, "Do the laundry");
    addTask(&head, 3, "Buy groceries");

    displayTasks(head);

    changeState(head, 2, IN_PROGRESS);

    printf("\nAfter changing state:\n");
    displayTasks(head);

    return 0;
}