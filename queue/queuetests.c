#include "queuetests.h"
#include "queue.h"

#include <assert.h>

void run_all_tests()
{
    test_enqueue();
    //test_dequeue();
    //test_empty();
}

void test_enqueue()
{
    queue q;
    create_queue(&q);

    enqueue(&q, 1);

    assert(q.list.head->data == 1);

    destroy_queue(&q);
}

void test_dequeue()
{
    queue q;
    create_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    assert(dequeue(&q) == 1);
    assert(q.list.head->data == 2);

    destroy_queue(&q);
}

void test_empty()
{
    queue q;
    create_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    assert(queue_is_empty == 1);

    destroy_queue(&q);
}
