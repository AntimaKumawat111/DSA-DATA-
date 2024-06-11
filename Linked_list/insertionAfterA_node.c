
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void triverse(struct node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("Element %d : %d\n",i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct node *insertionAfterNode(struct node *head, struct node *priviousNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
    ptr->next = priviousNode->next;
    priviousNode->next = ptr;
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 6;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = fifth;

    fifth->data = 10;
    fifth->next = NULL;

    printf("Before insertion\n");
    triverse(head);

    printf("After insertion\n");
    head = insertionAfterNode(head, second, 3);
    triverse(head);

    return 0;
}
