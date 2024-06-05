// Deleting a node of a linked list
// The memory of the last deleted value will also have to be freed.


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void triverLinkedList(struct node *ptr)
{
    int n = 0;
    while (ptr != NULL)
    {
        n++;
        printf(" Element %d : %d\n", n, ptr->data);
        ptr = ptr->next;
    }
}

struct node *deletionAtFirst(struct node *head)
{
    struct node *p = head;
    head = head->next;
    // the address next to the head will be pointed to the head and the head will be empty.
    free(p);
    return head; // Head has to be returned otherwise the value of head will not change
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    // memory reserve in heap
    head = (struct node *)malloc(sizeof(struct node *));
    second = (struct node *)malloc(sizeof(struct node *));
    third = (struct node *)malloc(sizeof(struct node *));
    fourth = (struct node *)malloc(sizeof(struct node *));
    // first link
    head->data = 5;
    head->next = second;

    // second link
    second->data = 56;
    second->next = third;

    // third link
    third->data = 78;
    third->next = fourth;

    // fourth link
    fourth->data = 89;
    fourth->next = NULL;

    printf("Before enter a new node\n");
    triverLinkedList(head);
    printf("After delete a node\n");
    head = deletionAtFirst(head);
    triverLinkedList(head);

    return 0;
}
