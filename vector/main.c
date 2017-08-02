#include "vector.h"

#include <stdio.h>

int main() {
    vector v;
    vector_init(&v);
    
    vector_push(&v, 7);
    vector_push(&v, 12);
    vector_push(&v, 3);
    vector_push(&v, 1); 
    vector_insert(&v, 2, 199);
    

    printf("is vec empty? %d\n", vector_is_empty(&v));

    printf("vec[3] == %d\n", vector_at(&v, 3));

    printf("pop vec == %d\n", vector_pop(&v));

    printf("vec[3] == %d\n", vector_at(&v, 3));

    vector_prepend(&v, 45);

    printf("vec[0] == %d\n", vector_at(&v, 0));
    printf("vec[1] == %d\n", vector_at(&v, 1));

    vector_delete(&v, 1);

    printf("vec[1] == %d\n", vector_at(&v, 1));
    
    return 0;
}