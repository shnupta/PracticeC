#ifndef _QUEUE_H
#define _QUEUE_H

#include "linkedlist.h"

typedef struct queue
{
    linkedlist list;
} queue;

void create_queue(queue *);
void enqueue(queue *, void *);
void *dequeue(queue *);
int queue_is_empty(queue *);
void destroy_queue(queue *);


#endif
