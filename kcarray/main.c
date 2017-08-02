#include "kcarray.h"

#include <stdio.h>

int main() {
    kcarray v;
    kcarray_init(&v);
    
    kcarray_push(&v, 7);
    kcarray_push(&v, 12);
    kcarray_push(&v, 3);
    kcarray_push(&v, 1); 
    kcarray_insert(&v, 2, 199);
    

    printf("is vec empty? %d\n", kcarray_is_empty(&v));

    printf("vec[3] == %d\n", kcarray_at(&v, 3));

    printf("pop vec == %d\n", kcarray_pop(&v));

    printf("vec[3] == %d\n", kcarray_at(&v, 3));

    kcarray_prepend(&v, 45);

    printf("vec[0] == %d\n", kcarray_at(&v, 0));
    printf("vec[1] == %d\n", kcarray_at(&v, 1));

    kcarray_delete(&v, 1);

    printf("vec[1] == %d\n", kcarray_at(&v, 1));

    kcarray_destroy(&v);

    return 0;
}
