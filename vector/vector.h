#ifndef _VECTOR_H
#define _VECTOR_H

#define VECTOR_INIT_CAPACITY 16

typedef struct vector {
    void **items;
    int size; 
    int capacity;
} vector;


void vector_init(vector *);
void vector_init_with_cap(vector *, int);
void vector_destroy(vector *);
int vector_size(vector *);
int vector_capacity(vector *);
int vector_is_empty(vector *);
void* vector_at(vector *, int);
void vector_push(vector *, void *);
void vector_insert(vector *, int, void *);
void vector_prepend(vector *, void *);
void *vector_pop(vector*);
void vector_delete(vector*, int);

#endif 