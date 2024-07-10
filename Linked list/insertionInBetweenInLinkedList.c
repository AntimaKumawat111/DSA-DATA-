
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void triverse(struct node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("element %d : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct node *insertionInBetween(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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

    int data, indexNumber;
    printf("Enter data ");
    scanf("%d", &data);
    printf("Enter indexNumber ");
    scanf("%d", &indexNumber);

    printf(" Before insertion\n");
    triverse(head);
    printf(" After insertion\n");
    head = insertionInBetween(head, data, indexNumber);
    triverse(head);

    return 0;
}
