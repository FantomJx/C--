#include <stdio.h>
#include <stdlib.h>

typedef struct vector_t
{
    int *arr;
    int size;
    int capacity;
} vector_t;

vector_t *init_vector(int FirstCapacity)
{
    vector_t *v = (vector_t*)malloc(FirstCapacity);
    v->arr = (int*)malloc(FirstCapacity * sizeof(int*));
    v->size = 0;
    v->capacity = FirstCapacity;

    return v;
}

void push_back(vector_t *v, int val)
{
    if (v->size + 1 > v->capacity) {
        v->capacity = v->capacity * 2;
        int *tp = (int*)realloc(v->arr, sizeof(int) * v->capacity);
        if (tp == NULL) {
            exit(1);
        }
        v->arr = tp;    
    }

    v->arr[v->size] = val;
    v->size++;

}

void clear(vector_t *v)
{
    free(v->arr);
    free(v);
    
}

void print_vector(vector_t *v)
{
    for(int i = 0; i < v->size; i++){
        printf("%d ", v->arr[i]);
    }
}

int binary_search(vector_t *v, int val, int r, int l)
{
    int pos;
    int mid = r / 2;

    if(v->size == 0){
        exit(-1);
    }
    if(val == mid) {
        return mid;
    }
    if(val < mid){
        binary_search(v, val, mid, 0);
    }
    else if (val > mid)
    {
        binary_search(v, val, v->size, mid);
    }
    else{
        printf("Not found");
    }

    return 0;
}

void insertion_sort(vector_t *v)
{
    for (int i = 0; i < v->size; i++)
    {
        int val = v->arr[i];
        int j = i - 1;
        while (j >= 0 && v->arr[j] > val) {
            binary_search(v, i, v->size, 0);
            v->arr[j + 1] = v->arr[j];
            j = j - 1;
        }
        v->arr[j + 1] = val;
        
    }
    
}

/*
    Задача използва рекурсия следователно сложноста е О(nlog(n)) и има вложен цикъл следователно сложност е O(n на втора)

*/

int main()
{
    vector_t *v = init_vector(7);

    push_back(v, 2);
    push_back(v, 0);
    push_back(v, -2);
    push_back(v, 7);
    push_back(v, 2);
    push_back(v, 6);
    push_back(v, -34);
    push_back(v, 112);
    push_back(v, 0);
    push_back(v, -134);
    push_back(v, 2);
    push_back(v, 2);
    push_back(v, 100);

    print_vector(v);
    insertion_sort(v);
    print_vector(v);


    clear(v);
}