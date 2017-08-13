#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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


void *list_value_at(linkedlist *list, int index)
{
	assert(index >= 0 && index < list->size);
	int cur = 0;
	for (listnode *node = list->head->next; node->next != list->tail->next; node = node->next)
	{
		if(cur == index)
		{
			return node->data;
		}
	}	
	return NULL;
}

void list_push_front(linkedlist *list, void *value)
{
	listnode *node = malloc(sizeof(listnode *));
	node->data = value;
	node->next = list->head->next;
	list->head->next = node;
	if(list->size == 0)
	{
		list->tail->next = node;
	}
	list->size++;
}

void *list_pop_front(linkedlist *list)
{
	assert(list->size > 0);
	void *retval = list->head->next->data;
	list->head->next = list->head->next->next;
	free(list->head->next);
	list->size--;

	return retval;
}
