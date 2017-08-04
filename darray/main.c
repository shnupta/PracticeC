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
    

    printf("is vec empty? %d\n", darray_is_empty(&v));

    printf("vec[3] == %d\n", darray_at(&v, 3));

    printf("pop vec == %d\n", darray_pop(&v));

    printf("vec[3] == %d\n", darray_at(&v, 3));

    darray_prepend(&v, 45);

    printf("vec[0] == %d\n", darray_at(&v, 0));
    printf("vec[1] == %d\n", darray_at(&v, 1));

    darray_delete(&v, 1);

    printf("vec[1] == %d\n", darray_at(&v, 1));

    darray_prepend(&v, 7);
    darray_prepend(&v, 7);
    darray_push(&v, 7);
    darray_push(&v, 8);
    darray_push(&v, 7);

    printf("vec[1] = %d\n", darray_at(&v, 1));

    darray_remove(&v, 7);

    printf("after remove (7)\nvec[1] = %d\n", darray_at(&v, 1));

    darray_destroy(&v);

    return 0;
}
