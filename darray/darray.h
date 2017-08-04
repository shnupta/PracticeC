#ifndef _DARRAY_H
#define _DARRAY_H

#define DARRAY_INIT_CAPACITY 16

typedef struct darray {
    void **items;
    int size; 
    int capacity;
} darray;


void darray_init(darray *);
void darray_init_with_cap(darray *, int);
void darray_destroy(darray *);
int darray_size(darray *);
int darray_capacity(darray *);
int darray_is_empty(darray *);
void* darray_at(darray *, int);
void darray_push(darray *, void *);
void darray_insert(darray *, int, void *);
void darray_prepend(darray *, void *);
void *darray_pop(darray*);
void darray_delete(darray*, int);
void darray_remove(darray*, void *);
int darray_find(darray*, void *);
void darray_resize(darray*, int);


#endif 
