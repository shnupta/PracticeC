#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main()
{
	linkedlist mylist;
	list_create(&mylist);
	list_push_front(&mylist, "Casey");
	printf("%s\n", list_value_at(&mylist, 0));
	printf("%s\n", list_pop_front(&mylist));
}
