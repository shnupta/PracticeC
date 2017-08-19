#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main()
{
	 linkedlist mylist;
	 list_create(&mylist);
	 list_push_front(&mylist, "one");
        list_push_back(&mylist, "three");
        list_insert(&mylist, 1, "two");
        printf("%s\n", list_value_at(&mylist, 1)); // woohoo!!
}
