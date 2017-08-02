#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "kcarray.h"

void kcarray_init(kcarray *vec) {
    vec->capacity = KCARRAY_INIT_CAPACITY;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity); // allocate memory based on size of void pointer timesed by capacity
}

void kcarray_init_with_cap(kcarray *vec, int capacity) {
    vec->capacity = capacity;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity);
}

void kcarray_destroy(kcarray *vec) {
    free(vec->items);
}

int kcarray_size(kcarray *vec) {
    return vec->size;
}

int kcarray_capacity(kcarray *vec) {
    return vec->capacity;
}

int kcarray_is_empty(kcarray *vec) {
    return (vec->size == 0);
}

void* kcarray_at(kcarray *vec, int index) {
    assert(index < vec->size && index >= 0);
    return *(vec->items + sizeof(void *) * index);
}

void kcarray_push(kcarray *vec, void *item) {
    // for now just push a value, do the resizing later
    if (vec->size == vec->capacity) {
        // resize the kcarray
    }


    *(vec->items + sizeof(void *) * vec->size) = item;
    vec->size++;
}

void kcarray_insert(kcarray *vec, int index, void *item) {
    // same as above until resize function implemented
    if(vec->size == vec->capacity) {

    }  

    for (int i = vec->size - 1; i >= index; i--) {
        *(vec->items + sizeof(void *) * (i + 1)) = *(vec->items + sizeof(void *) * i);
    }

    *(vec->items + sizeof(void *) * index) = item;
    vec->size++;
}

void kcarray_prepend(kcarray *vec, void *item) {
    kcarray_insert(vec, 0, item);
}

void* kcarray_pop(kcarray *vec) {
    if(vec->size <= vec->capacity / 4) {
        // half the capacity in resize
    }

    void *ret_val = *(vec->items + sizeof(void *) * (vec->size-1));
    *(vec->items + sizeof(void *) * (vec->size-1)) = NULL;

    vec->size--;
    
    return ret_val;
}

void kcarray_delete(kcarray *vec, int index) {
    if(vec->size <= vec->capacity / 4) {
        // half the capacity in resize
    }

    *(vec->items + sizeof(void *) * index) = NULL;
    
    for (int i = index; i < vec->size; i++) {
        *(vec->items + sizeof(void *) * i) = *(vec->items + sizeof(void *) * (i+1));
    }

    vec->size--;
}







