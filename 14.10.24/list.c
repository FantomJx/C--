#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    return node;
}

LList* init_llist() {
    LList* l = (LList*)malloc(sizeof(LList));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void insertBegin(LList* l, int val) {
    Node* newNode = init_node(val);
    if (l->head == NULL) { 
        l->head = l->tail = newNode;
    } else {
        newNode->next = l->head;
        l->head->prev = newNode;
        l->head = newNode;
    }
}

void insertEnd(LList* l, int val) {
    Node* newNode = init_node(val);
    if (l->tail == NULL) { 
        l->head = l->tail = newNode;
    } else {
        newNode->prev = l->tail;
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

int popBegin(LList* l) {
    if (l->head == NULL) {
        printf("Cannot pop from empty list\n");
        exit(1);
    }
    Node* tmp = l->head;
    int val = tmp->val;
    l->head = l->head->next;
    if (l->head != NULL) {
        l->head->prev = NULL;
    } else {
        l->tail = NULL;
    }
    free(tmp);
    return val;
}

int popEnd(LList* l) {
    if (l->tail == NULL) {
        printf("Cannot pop from empty list\n");
        exit(1);
    }
    Node* tmp = l->tail;
    int val = tmp->val;
    l->tail = l->tail->prev;
    if (l->tail != NULL) {
        l->tail->next = NULL;
    } else {
        l->head = NULL;
    }
    free(tmp);
    return val;
}

void insertBefore(Node* n, int val) {
    if (n == NULL) return;
    Node* newNode = init_node(val);
    newNode->next = n;
    newNode->prev = n->prev;
    if (n->prev != NULL) {
        n->prev->next = newNode;
    }
    n->prev = newNode;
}

Node* getAt(LList* l, int index) {
    Node *it = l->head;
    for (int i = 0; i < index; i++) {
        if (it == NULL) {
            printf("Index out of bounds\n");
            exit(1);
        }
        it = it->next;
    }
    return it;
}

Node* getMid(LList* l) {
    Node *slow = l->head, *fast = l->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(LList *l) {
    Node *it = l->head;
    while (it != NULL) {
        printf("%d ", it->val);
        it = it->next;
    }
    printf("\n");
}

void clear(LList* l) {
    Node* it = l->head;
    while (it != NULL) {
        Node* tmp = it;
        it = it->next;
        free(tmp);
    }
    l->head = l->tail = NULL;
}

void freeList(LList* l) {
    clear(l);
    free(l);
}

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortList(LList* l) {
    if (l->head == NULL) return;
    Node* sorted = l->head;
    Node* curr = sorted->next;
    sorted->next = NULL; 
    while (curr != NULL) {
        Node* next = curr->next;
        if (curr->val < sorted->val) {
            curr->next = sorted;
            sorted->prev = curr;
            sorted = curr;
        } else {
            Node* it = sorted;
            while (it->next != NULL && it->next->val < curr->val) {
                it = it->next;
            }
            curr->next = it->next;
            if (it->next != NULL) {
                it->next->prev = curr;
            }
            it->next = curr;
            curr->prev = it;
        }
        curr = next;
    }
    l->head = sorted;
}

#include "list.h"
#include <stdio.h>

int hasCycle(LList* l) {
    if (l->head == NULL) {
        return 0; 
    }

    Node* slow = l->head;
    Node* fast = l->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;    

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

