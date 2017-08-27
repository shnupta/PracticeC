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
	for (listnode *node = list->head->next; node != NULL; node = node->next)
	{
		if(cur == index)
		{
			return node->data;
		}
               cur++;
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
  listnode *next = list->head->next->next;
	free(list->head->next);
	list->head->next = next;
	list->size--;

	return retval;
}


void list_push_back(linkedlist *list, void *value)
{
	listnode *node = malloc(sizeof(listnode *));
	node->data = value;
	node->next = NULL;
	list->tail->next->next = node;
	list->tail->next = node;
	if(list->size == 0)
	{
		list->head->next = node;
	}
	list->size++;
}

void *list_pop_back(linkedlist *list)
{
	assert(list->size > 0);
	void *retval = list->tail->next->data;
	for(listnode *node = list->head->next; node->next != NULL; node = node->next)
	{
		if(node->next  == list->tail->next)
		{
			// we have the penultimate element
			free(list->tail->next);
			list->tail->next = node;
			node->next = NULL;
		}
	}
	list->size--;
	return retval;
}

void *list_front(linkedlist *list)
{
	assert(list->size > 0);
	return list->head->next->data;
}

void *list_back(linkedlist *list)
{
	assert(list->size > 0);
	return list->tail->next->data;
}

void list_insert(linkedlist *list, int index, void *value)
{
        assert(index >= 0 && index < list->size);

        if(index == 0) // first item
        {
                list_push_front(list, value);
                return;
        }
        if(index == list->size) // add to end
        {
            list_push_back(list, value);
            return;
        }
        listnode *node = malloc(sizeof(listnode *));
        node->data = value;
        int cur_index = 0;
        for(listnode *cur = list->head->next; cur != NULL; cur = cur->next)
        {
                if (cur_index == index - 1)
                {
                        // here is where we need to reassign pointers
                        node->next = cur->next;
                        cur->next = node;
                        return;
                }
                cur_index++;
        }
        list->size++;
}


void list_erase(linkedlist *list, int index)
{
        assert(index >= 0 && index < list->size);
        if(index == 0)
        {
                list_pop_front(list);
                return;
        }
        if(index == list->size - 1)
        {
                list_pop_back(list);
                return;
        }
        // else we need to remove in the middle of the list
        int cur = 0; 
        listnode *prev;
        for (listnode *node = list->head->next; node != NULL; node = node->next)
        {
                if(cur == index)
                {
                        prev->next = node->next;
                        free(node);
                        list->size--;
                        return;
                }
                prev = node;
                cur++;
        }
}


void *list_value_n_from_end(linkedlist *list, int n)
{

}
