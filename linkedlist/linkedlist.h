#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct listnode
{
	void *data;
	struct listnode *next;
} listnode;

typedef struct linkedlist 
{
	int size;
	listnode *head;
	listnode *tail;
} linkedlist;

void list_create(linkedlist *); //
int list_size(linkedlist *); //
int list_is_empty(linkedlist *); //
void *list_value_at(linkedlist *, int); //
void list_push_front(linkedlist *, void *); //
void *list_pop_front(linkedlist *); //
void list_push_back(linkedlist *, void *); //
void *list_pop_back(linkedlist *); //
void *list_front(linkedlist *); //
void *list_back(linkedlist *); //
void list_insert(linkedlist *, int, void *); //
void list_erase(linkedlist *, int); //
void *list_value_n_from_end(linkedlist *, int); //
void list_reverse(linkedlist *); //
void list_reverse_please(listnode *); //
void list_remove(linkedlist *, void *); //
void list_destroy(linkedlist *); //

#endif
