#ifndef DYNARR_H
#define DYNARR_H

typedef struct {
    char name[100];
    char author[100];
    char genre[50];
    int year;
    int ISBN;
} Book;

typedef struct {
    Book *buffer;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int capacity);
void pushBack(DynamicArray *arr, Book book);
void removeElement(DynamicArray *arr, int index);
int findISBN(DynamicArray *arr, int ISBN);
void release(DynamicArray *arr);

#endif
