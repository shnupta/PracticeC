#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void create_queue(queue *q)
{
    list_create(&q->list);
}

void enqueue(queue *q, void *value)
{
    list_push_back(&q->list, value);
}

void *dequeue(queue *q)
{
    return list_pop_front(&q->list);
}

int queue_is_empty(queue *q)
{
    return list_is_empty(&q->list);
}

void destroy_queue(queue *q)
{
    list_destroy(&q->list);
    q = NULL;
}
