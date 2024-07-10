#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void triverse(struct node *ptr);
void reverseTriverse(struct node *ptr);

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

    head->data = 23;
    head->prev = NULL;
    head->next = second;

    second->data = 24;
    second->prev = head;
    second->next = third;

    third->data = 25;
    third->prev = second;
    third->next = fourth;

    fourth->data = 26;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 27;
    fifth->prev = fourth;
    fifth->next = NULL;
    printf("Triverse :- \n");
    triverse(head);
    printf("Reverse Triversal :- \n");
    reverseTriverse(head);

    return 0;
}

void triverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverseTriverse(struct node *ptr)
{
    struct node *last = NULL;
    while (ptr != NULL)
    {

        last = ptr;
        ptr = ptr->next;
    }
    // printf("\n");
    while (last != NULL)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
