#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void list_create(linkedlist *list)
{
	list->head = malloc(sizeof(listnode *));
	list->tail = malloc(sizeof(listnode *));
	list->head = NULL;
	list->tail = NULL;
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
	int cur_index = 0;
  listnode *cur = list->head;
  while(cur)
  {
          if(cur_index == index) return cur->data;
          cur_index++;
          cur = cur->next;
  }
	return NULL;
}

void list_push_front(linkedlist *list, void *value)
{
	listnode *node = malloc(sizeof(listnode *));
	node->data = value;
	node->next = list->head;
	list->head = node;
	if(list->size == 0)
	{
		list->tail = node;
	}
	list->size++;
}

void *list_pop_front(linkedlist *list)
{
	assert(list->size > 0);
	void *retval = list->head->data;
  listnode *next = list->head->next;
	free(list->head);
	list->head = next;
	list->size--;

	return retval;
}


void list_push_back(linkedlist *list, void *value)
{
	listnode *node = malloc(sizeof(listnode *));
	node->data = value;
	node->next = NULL;
	if(list->size == 0)
	{
      list->tail = node;
      list->head = node;
	}
  else
  {
      list->tail->next = node;
      list->tail = node;
  }
	list->size++;
}

void *list_pop_back(linkedlist *list)
{
	assert(list->size > 0);
	void *retval = list->tail->data;

  listnode *cur = list->head;
  listnode *prev = NULL;
  while(cur)
  {
          if(cur == list->tail) 
          {
                  free(list->tail);
                  list->tail = prev;
                  prev->next = NULL;
          }
          prev = cur;
          cur = cur->next;
  }
	list->size--;
	return retval;
}

void *list_front(linkedlist *list)
{
	assert(list->size > 0);
	return list->head->data;
}

void *list_back(linkedlist *list)
{
	assert(list->size > 0);
	return list->tail->data;
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
        listnode *cur = list->head;
        listnode *prev = NULL;
        while(cur)
        {
                if(cur_index == index)
                {
                        node->next = prev->next;
                        prev->next = node;
                        list->size++;
                        return;
                }
                cur_index++;
                prev = cur;
                cur = cur->next;
        }
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
        int cur_index = 0; 
        listnode *prev = NULL;
        listnode *cur = list->head;
        while(cur)
        {
                if(cur_index == index)
                {
                        prev->next = cur->next;
                        free(cur);
                        list->size--;
                        return;
                }
                cur_index++;
                cur = cur->next;
        }
}


void *list_value_n_from_end(linkedlist *list, int n)
{
        assert(n < list->size && n >= 0);
        int diff = list->size - n - 1; // -1 because of zero based indexing
        listnode *cur = list->head;
        while(cur)
        {
                if(diff == 0) return cur->data;
                diff--;
                cur = cur->next;
        }
}

void list_reverse(linkedlist *list)
{
        assert(list->size > 1);
        list->tail = list->head;

        listnode *cur = list->head;
        listnode *next = list->head;
        listnode *prev = NULL;

        while(cur)
        {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
        }

        list->head = prev;


        return;
}

void list_remove(linkedlist *list, void *item)
{
        listnode *prev = NULL;
        listnode *cur = list->head;
        while(cur)
        {
                if(cur->data == item)
                {
                        if(prev) prev->next = cur->next;
                        else list->head = cur->next;

                        if(list->tail == cur) list->tail = prev;

                        free(cur);
                        list->size--;
                        return;
                }
                prev = cur;
                cur = cur->next;
        }
}

void list_destroy(linkedlist *list)
{
        listnode *cur = list->head;

        while(cur)
        {
                listnode *next = cur->next;
                free(cur);
                cur = next;
        }
}
