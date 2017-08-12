#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void list_create(linkedlist *list)
{
	list->head = malloc(sizeof(listnode *));
	list->tail = malloc(sizeof(listnode *));
	list->head->next = NULL;
	list->tail->next = NULL;
	list->size = 0;
}

int list_size(linkedlist *list)
{
	return list->size;
}

int list_is_empty(linkedlist *list)
{
	return 1 ? 0 : list->size == 0;
}
