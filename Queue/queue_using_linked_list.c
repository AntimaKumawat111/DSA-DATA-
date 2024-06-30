#include <stdio.h>
#include <stdlib.h>
struct node *firstend = NULL;
struct node *backend = NULL;

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

void enqueue(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(int));
    if (ptr == NULL) // Linkedlist full condition
        printf("Queue is full\n");
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (firstend == NULL)// This is a spcial case in Linkedlisted queue
        {
            firstend = backend = ptr; 
        }
        else
        {
            backend->next = ptr;
            backend = ptr;
        }
    }
}

int dequeue()
{
    struct node *sp = firstend;
    int value = -1;
    if (firstend == NULL) //Linkedlist Empty  condition
        printf("Queue is empty\n");
    else
    {
        value = firstend->data;
        firstend = firstend->next;
        free(sp);
    }
    return value;
}

int main()
{
    printf("Before enqueue\n");
    triverLinkedList(firstend);
    printf("Dequeueing element is : %d\n", dequeue());
    printf("\n");
    printf("After enqueue\n");
    enqueue(56);
    enqueue(57);
    enqueue(58);
    enqueue(59);
    enqueue(60);
    triverLinkedList(firstend);
    printf("\n");
    printf("After dequeue\n");
    printf("Dequeueing element is : %d\n", dequeue());
    printf("Dequeueing element is : %d\n", dequeue());
    printf("Dequeueing element is : %d\n", dequeue());
    printf("Dequeueing element is : %d\n", dequeue());
    printf("Dequeueing element is : %d\n", dequeue());
    printf("Dequeueing element is : %d\n", dequeue());

    return 0;
}