#ifndef H_LIST_
#define H_LIST_

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;   
} Node;

typedef struct LList {
    Node* head;
    Node* tail;         
} LList;

Node* init_node(int val);
LList* init_llist();

void insertBegin(LList* l, int val);
void insertEnd(LList* l, int val);   
void insertBefore(Node* n, int val); 

int popBegin(LList* l);
int popEnd(LList* l);                

Node* getAt(LList* l, int i);
Node* getMid(LList* l);              

void insertionSort(int* arr, int n);  
void insertionSortList(LList* l);     

void printList(LList *l);
void clear(LList* l);
void freeList(LList* l);
int hasCycle(LList * l);

#endif
