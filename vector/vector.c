#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_init(vector *vec) {
    vec->capacity = VECTOR_INIT_CAPACITY;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity); // allocate memory based on size of void pointer trimesed bby the capacityß
}

void vector_destroy(vector *vec) {
    free(vec->items);
}