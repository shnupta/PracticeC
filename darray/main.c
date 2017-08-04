#include "darray.h"

#include <stdio.h>

int main() {
    darray v;
    darray_init(&v);
    
    darray_push(&v, 7);
    darray_push(&v, 12);
    darray_push(&v, 3);
    darray_push(&v, 1); 
    darray_insert(&v, 2, 199);
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    darray_push(&v, 96);    
    printf("size now is %d\n", darray_capacity(&v));
    printf("vec[5] = %d\n", darray_at(&v, 5));


    return 0;
}
