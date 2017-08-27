#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main()
{
        linkedlist mylist;
        list_create(&mylist);
        list_push_front(&mylist, 1);
        list_push_back(&mylist, 2);
        list_push_back(&mylist, 3);
        for (listnode *node = mylist.head->next; node != NULL; node = node->next)
          {
                  printf("%d -> ", node->data);
          }

        list_reverse(&mylist);
        printf("\n");
        for (listnode *noden = mylist.head->next; noden != NULL; noden = noden->next)
        {
                printf("%d -> ", noden->data);
        }
}
