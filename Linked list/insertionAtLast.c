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
        printf("Element %d = %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct node *insertionAtLast(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
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

    head->data = 89;
    head->next = second;

    second->data = 88;
    second->next = third;

    third->data = 87;
    third->next = fourth;

    fourth->data = 86;
    fourth->next = fifth;

    fifth->data = 85;
    fifth->next = NULL;
    int element;
    printf("Enter element ");
    scanf("%d", &element);
    printf("Before insertion at last \n");
    triverse(head);
    printf("After insertion at last \n");

    head = insertionAtLast(head, element);
    triverse(head);

    return 0;
}