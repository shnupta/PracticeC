#include "listtests.h"
#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void run_all_tests()
{
        test_size();
        test_empty();
        test_value_at();
        test_push_front();
        test_pop_front();
        test_push_back();
        test_pop_back();
        test_front();
        test_insert();
        test_erase();
        test_from_end();
        test_reverse();
        test_remove();
}


void test_size()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        assert(list_size(&list) == 3);

        list_destroy(&list);
}

void test_empty()
{
        linkedlist list;
        list_create(&list);

        assert(list_is_empty(&list) == 0);

        list_destroy(&list);
}

void test_value_at()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        assert(list_value_at(&list, 1) == 2);

        list_destroy(&list);
}

void test_push_front()
{
        linkedlist list;
        list_create(&list);

        list_push_front(&list, 3);
        list_push_front(&list, 2);
        list_push_front(&list, 1);

        assert(list.head->data == 1);
        assert(list.head->next->data == 2);
        assert(list.head->next->next->data == 3);

        list_destroy(&list);
}

void test_pop_front()
{
        linkedlist list;
        list_create(&list);

        list_push_front(&list, 3);
        list_push_front(&list, 2);
        list_push_front(&list, 1);

        assert(list_pop_front(&list) == 1);

        list_destroy(&list);

}

void test_push_back()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        assert(list.head->data == 1);
        assert(list.head->next->data == 2);
        assert(list.head->next->next->data == 3);

        list_destroy(&list);
}

void test_pop_back()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        assert(list_pop_back(&list) == 3);

        list_destroy(&list);
}

void test_front()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        assert(list_front(&list) == 1);

        list_destroy(&list);
}

void test_back()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        assert(list_back(&list) == 3);

        list_destroy(&list);
}

void test_insert()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 4);

        list_insert(&list, 2, 3);

        assert(list_value_at(&list, 2) == 3);

        list_destroy(&list);
}

void test_erase()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 4);

        list_insert(&list, 2, 3);

        list_erase(&list, 3);

        assert(list.tail->data == 3);

        list_destroy(&list);

}


void test_from_end()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);
        list_push_back(&list, 4);
        list_push_back(&list, 5);
        list_push_back(&list, 6);

        assert(list_value_n_from_end(&list, 2) == 4);

        list_destroy(&list);
}

void test_reverse()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        list_reverse(&list);

        assert(list.head->data == 3);
        assert(list.head->next->data == 2);
        assert(list.head->next->next->data == 1);

        list_destroy(&list);
}

void test_remove()
{
        linkedlist list;
        list_create(&list);

        list_push_back(&list, 1);
        list_push_back(&list, 2);
        list_push_back(&list, 3);

        list_remove(&list, 2);

        assert(list.head->data == 1);
        assert(list.head->next->data == 3);

        list_destroy(&list);
}
