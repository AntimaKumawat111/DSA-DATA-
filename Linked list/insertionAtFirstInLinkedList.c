// linked list ko creat krke triverse karna

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

struct node *insertLinkAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

int main()
{
    struct node *head;
    struct node *second;

    // memory reserve in heap
    head = (struct node *)malloc(sizeof(struct node *));
    second = (struct node *)malloc(sizeof(struct node *));

    // first link
    head->data = 5;
    head->next = second;

    // second link
    second->data = 56;
    second->next = NULL;

    int data;
    printf("Enter number ");
    scanf("%d", &data);

    printf("Before enter a new node\n");
    triverLinkedList(head); // function call

    printf("After enter a new node at first\n");
    head = insertLinkAtFirst(head, data); // function call
    triverLinkedList(head);               // function call

    return 0;
}
