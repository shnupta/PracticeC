#ifndef _KCARRAY_H
#define _KCARRAY_H

#define KCARRAY_INIT_CAPACITY 16

typedef struct kcarray {
    void **items;
    int size; 
    int capacity;
} kcarray;


void kcarray_init(kcarray *);
void kcarray_init_with_cap(kcarray *, int);
void kcarray_destroy(kcarray *);
int kcarray_size(kcarray *);
int kcarray_capacity(kcarray *);
int kcarray_is_empty(kcarray *);
void* kcarray_at(kcarray *, int);
void kcarray_push(kcarray *, void *);
void kcarray_insert(kcarray *, int, void *);
void kcarray_prepend(kcarray *, void *);
void *kcarray_pop(kcarray*);
void kcarray_delete(kcarray*, int);

#endif 
