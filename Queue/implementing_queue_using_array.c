#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int backend;// backend is the element that tracks the last element in the array
    int firstend;// firstend is the element that tracks first element in the array
    
    char *arr;
} sq;

int isEmpty(sq *sp)
{
    if (sp->backend == sp->firstend)
        return 1;
    return 0;
}

int isFull(sq *sp)
{
    if (sp->backend == sp->size - 1)
        return 1;
    return 0;
}


int main()
{
    sq *sp = (sq *)malloc(sizeof(sq));
    sp->backend = -1;
    sp->firstend = -1;
    sp->size = 4;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    printf("Empty :%d\n", isEmpty(sp));
    printf("Full :%d\n", isFull(sp));

   
    return 0;
}