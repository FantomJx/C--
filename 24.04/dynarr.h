#ifndef DYN_ARR_H
#define DYN_ARR_H

typedef float DynArrType;
typedef unsigned int uint;

typedef struct {
  DynArrType * buffer;
  uint size;
  uint capacity;
} DynamicArray;

DynamicArray init(uint capacity);

void push(DynamicArray * arr, uint index, DynArrType value);
void pushFront(DynamicArray * arr, DynArrType value);
void pushBack(DynamicArray * arr, DynArrType value);

void setElement(DynamicArray * arr, uint index, DynArrType value);
DynArrType getElement(DynamicArray * arr, uint index);

DynArrType removeElement(DynamicArray * arr, uint index);
DynArrType popFront(DynamicArray * arr);
DynArrType popBack(DynamicArray * arr);
int findIndex(DynamicArray * arr, DynArrType elem);
void release(DynamicArray * arr);

#endif
