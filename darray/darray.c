#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "darray.h"

void darray_init(darray *vec) {
    vec->capacity = DARRAY_INIT_CAPACITY;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity); // allocate memory based on size of void pointer timesed by capacity
}

void darray_init_with_cap(darray *vec, int capacity) {
    vec->capacity = capacity;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity);
}

void darray_destroy(darray *vec) {
    free(vec->items);
}

int darray_size(darray *vec) {
    return vec->size;
}

int darray_capacity(darray *vec) {
    return vec->capacity;
}

int darray_is_empty(darray *vec) {
    return (vec->size == 0);
}

void* darray_at(darray *vec, int index) {
    assert(index < vec->size && index >= 0);
    return *(vec->items + sizeof(void *) * index);
}

void darray_push(darray *vec, void *item) {
    // for now just push a value, do the resizing later
    if (vec->size == vec->capacity) {
        // resize the darray
    }


    *(vec->items + sizeof(void *) * vec->size) = item;
    vec->size++;
}

void darray_insert(darray *vec, int index, void *item) {
    // same as above until resize function implemented
    if(vec->size == vec->capacity) {

    }  

    for (int i = vec->size - 1; i >= index; i--) {
        *(vec->items + sizeof(void *) * (i + 1)) = *(vec->items + sizeof(void *) * i);
    }

    *(vec->items + sizeof(void *) * index) = item;
    vec->size++;
}

void darray_prepend(darray *vec, void *item) {
    darray_insert(vec, 0, item);
}

void* darray_pop(darray *vec) {
    if(vec->size <= vec->capacity / 4) {
        // half the capacity in resize
    }

    void *ret_val = *(vec->items + sizeof(void *) * (vec->size-1));
    *(vec->items + sizeof(void *) * (vec->size-1)) = NULL;

    vec->size--;
    
    return ret_val;
}

void darray_delete(darray *vec, int index) {
    if(vec->size <= vec->capacity / 4) {
        // half the capacity in resize
    }

    *(vec->items + sizeof(void *) * index) = NULL;
    
    for (int i = index; i < vec->size; i++) {
        *(vec->items + sizeof(void *) * i) = *(vec->items + sizeof(void *) * (i+1));
    }

    vec->size--;
}


void darray_remove(darray *vec, void *item) {
    for(int i = 0; i < vec->size; i++) {
        if (*(vec->items + sizeof(void *) * i) == item) {
            darray_delete(vec, i);
        }
    }
}






