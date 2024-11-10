#include "dynarr.h"
#include <stdlib.h>
#include <string.h>

void initArray(DynamicArray *arr, int capacity) {
    arr->buffer = malloc(sizeof(Book) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
}

void pushBack(DynamicArray *arr, Book book) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->buffer = realloc(arr->buffer, sizeof(Book) * arr->capacity);
    }
    arr->buffer[arr->size++] = book;
}

void removeElement(DynamicArray *arr, int index) {
    if (index >= 0 && index < arr->size) {
        for (int i = index; i < arr->size - 1; i++) {
            arr->buffer[i] = arr->buffer[i + 1];
        }
        arr->size--;
    }
}

int findISBN(DynamicArray *arr, int ISBN) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->buffer[i].ISBN == ISBN) {
            return i;
        }
    }
    return -1;
}

void release(DynamicArray *arr) {
    free(arr->buffer);
    arr->buffer = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
