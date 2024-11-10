#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char firstname[50];
    struct Node *father;
    struct Node *mother;
    struct Node *marriedto;
} Node;

Node *createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->firstname, name);
    newNode->father = NULL;
    newNode->mother = NULL;
    newNode->marriedto = NULL;
    return newNode;
}

void addCouple(Node *person1, Node *person2) {
    if (person1 != NULL && person2 != NULL) {
        person1->marriedto = person2;
        person2->marriedto = person1;
    }
}

void addChild(Node *parent, Node *child) {
        if (parent->marriedto != NULL) {
            child->father = parent;
            child->mother = parent->marriedto;
        } else {
            child->mother = parent;
        }
}


int main() {
    Node *grandpa = createNode("Dqdo");
    Node *grandma = createNode("Babenceto");
    Node *dad = createNode("Batq");
    Node *mom = createNode("Svetlana");
    Node *me = createNode("Mark");
    Node *sibling = createNode("Eva");

    addCouple(grandpa, grandma);
    addCouple(dad, mom);
    addChild(dad, me);
    addChild(dad, sibling);

    free(grandpa);
    free(grandma);
    free(dad);
    free(mom);
    free(me);
    free(sibling);

    return 0;
}
