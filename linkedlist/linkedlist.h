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

void list_create(linkedlist *);
int list_size(linkedlist *);
int list_is_empty(linkedlist *);
void *list_value_at(int);
void list_push_front(void *);
void *list_pop_front();
void list_push_back(void *);
void *list_pop_back();
void *list_front();
void *list_back();
void *list_insert(int, void *);
void list_erase(int);
void *list_value_n_from_end(int);
void list_reverse();
void list_remove(void *);

#endif
