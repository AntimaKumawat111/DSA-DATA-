
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr)
{

    if (ptr->top == ptr->size - 1) 
    {
        return 1; // 1 return means the file is full , it is true
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top < 0) 
    {
        return 1; // 1 return means the file is empty , it is true
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s;
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    if ((isfull(s)))
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("The stack is not full\n");
    }
}
