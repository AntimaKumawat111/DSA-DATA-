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

struct node *deletionAtLast(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL) // q ka next jse hi null hoga loop ruk jayega
    {
        p = p->next; // jb tk q ka next null nhi h tb tk
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
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
    head = deletionAtLast(head);
    triverLinkedList(head);

    return 0;
}
