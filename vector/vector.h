#ifndef _VECTOR_H
#define _VECTOR_H

#define VECTOR_INIT_CAPACITY 16

typedef struct vector {
    void **items;
    int size; 
    int capacity;
} vector;


void vector_init(vector *);
void vector_destroy(vector *);

#endif 