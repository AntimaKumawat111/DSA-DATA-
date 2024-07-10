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

void enqueue(sq *sp, int element)
{
    if (isFull(sp))
        printf("Queue is already full\n");
    else
    {
        sp->backend++;
        sp->arr[sp->backend] = element;
    }
}

int main()
{
    sq *sp = (sq *)malloc(sizeof(sq));
    sp->backend = -1;
    sp->firstend = -1;
    sp->size = 4;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    printf("Before insertion a element in Queue \n");
    printf("Empty :%d\n", isEmpty(sp));
    printf("Full :%d\n", isFull(sp));
    printf("After insertion a element in Queue \n");
    enqueue(sp,67);
    printf("Empty :%d\n", isEmpty(sp));
    printf("Full :%d\n", isFull(sp));

    return 0;
}