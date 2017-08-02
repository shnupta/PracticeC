#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "vector.h"

void vector_init(vector *vec) {
    vec->capacity = VECTOR_INIT_CAPACITY;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity); // allocate memory based on size of void pointer timesed by capacity
}

void vector_init_with_cap(vector *vec, int capacity) {
    vec->capacity = capacity;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity);
}

void vector_destroy(vector *vec) {
    free(vec->items);
}

int vector_size(vector *vec) {
    return vec->size;
}

int vector_capacity(vector *vec) {
    return vec->capacity;
}

int vector_is_empty(vector *vec) {
    return (vec->size == 0);
}

void* vector_at(vector *vec, int index) {
    assert(index < vec->size && index >= 0);
    return *(vec->items + sizeof(void *) * index);
}

void vector_push(vector *vec, void *item) {
    // for now just push a value, do the resizing later
    if (vec->size == vec->capacity) {
        // resize the vector
    }


    *(vec->items + sizeof(void *) * vec->size) = item;
    vec->size++;
}

void vector_insert(vector *vec, int index, void *item) {
    // same as above until resize function implemented
    if(vec->size == vec->capacity) {

    }  

    for (int i = vec->size - 1; i >= index; i--) {
        *(vec->items + sizeof(void *) * (i + 1)) = *(vec->items + sizeof(void *) * i);
    }

    *(vec->items + sizeof(void *) * index) = item;
    vec->size++;
}

void vector_prepend(vector *vec, void *item) {
    vector_insert(vec, 0, item);
}

void* vector_pop(vector *vec) {
    if(vec->size <= vec->capacity / 4) {
        // half the capacity in resize
    }

    void *ret_val = *(vec->items + sizeof(void *) * (vec->size-1));
    *(vec->items + sizeof(void *) * (vec->size-1)) = NULL;

    vec->size--;
    
    return ret_val;
}

void vector_delete(vector *vec, int index) {
    if(vec->size <= vec->capacity / 4) {
        // half the capacity in resize
    }

    *(vec->items + sizeof(void *) * index) = NULL;
    
    for (int i = index; i < vec->size; i++) {
        *(vec->items + sizeof(void *) * i) = *(vec->items + sizeof(void *) * (i+1));
    }

    vec->size--;
}







