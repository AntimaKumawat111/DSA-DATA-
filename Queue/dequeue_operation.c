#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int backend;
    int firstend;
    char *arr;
} sq;

int isEmpty(sq *sp)
{
    if (sp->backend == -1)
        return 1;
    return 0;
}

int isFull(sq *sp)
{
    if (sp->backend == sp->size - 1)
        return 1;
    return 0;
}

void enqueue(sq *sp, int element) // enqueue means insertion
{

    if (isFull(sp))
        printf("Queue is already full\n");
    else
    {
        sp->backend++;
        sp->arr[sp->backend] = element;
    }
}

int dequeue(sq *sp) // dequeue means deletion
{
    int a = -1; //a  Will store the element that is being dequeue.
    if (isEmpty(sp))
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        sp->firstend++;
        a = sp->arr[sp->firstend]; 
    }
    return a;
    
}

int main()
{
    sq *sp = (sq *)malloc(sizeof(sq));
    sp->backend = -1;
    sp->firstend = -1;
    sp->size = 10;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    printf("Before insertion a element in Queue \n");
    printf("Empty :%d\n", isEmpty(sp));
    printf("Full :%d\n", isFull(sp));
    printf("\n");

    printf("After insertion in Queue \n");
    enqueue(sp, 4);
    enqueue(sp, 6);
    printf("Empty :%d\n", isEmpty(sp));
    printf("Full :%d\n", isFull(sp));
    printf("\n");

    printf("After deletion a element from Queue \n");
    printf("Dequeue element is %d \n", dequeue(sp));
    printf("Dequeue element is %d \n", dequeue(sp));
    printf("Dequeue element is %d \n", dequeue(sp));


    return 0;
}