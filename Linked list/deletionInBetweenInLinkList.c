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
        printf(" Element %d : %d\n", n, ptr->data);
        ptr = ptr->next;
        n++;
    }
}

struct node *deletionInBetween(struct node *head, int index)
{
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    // memory reserve in heap
    head = (struct node *)malloc(sizeof(struct node *));
    second = (struct node *)malloc(sizeof(struct node *));
    third = (struct node *)malloc(sizeof(struct node *));
    fourth = (struct node *)malloc(sizeof(struct node *));
    fifth = (struct node *)malloc(sizeof(struct node *));
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
    fourth->next = fifth;

    fifth->data = 67;
    fifth->next = NULL;
    printf("Before enter a new node\n");
    triverLinkedList(head);
    printf("After delete a node\n");
    head = deletionInBetween(head, 3);
    triverLinkedList(head);

    return 0;
}
