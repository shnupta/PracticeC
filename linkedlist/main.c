#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main()
{
        linkedlist mylist;
        list_create(&mylist);
        list_push_front(&mylist, 1);
        list_push_back(&mylist, 2);
        list_push_back(&mylist, 3);
        list_erase(&mylist, 1);
        printf("List value at 1 = %d\n", list_value_at(&mylist, 1));
        printf("List size = %d\n", list_size(&mylist));
}
