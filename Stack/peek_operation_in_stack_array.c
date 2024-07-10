

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *sp, int element)
{
    if (isFull(sp))
    {
        printf("Stack is overflow !, Can't push %d element\n", element);
    }
    else
    {
        sp->arr[++sp->top] = element;
    }
}

int peek(struct stack *sp, int positionNumber)
{
    int arrayIP = sp->top - positionNumber + 1;
    // this is the formula of change positionNumber to index number
    if (arrayIP < 0)
    {
        printf("Invalid position ! , Try again.\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayIP]; 
    }
}
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}
int main()
{
    struct stack *stackPointer = (struct stack *)malloc(sizeof(struct stack));
    int s;
    printf("What size do you want to have of stack : ");
    scanf("%d", &s);
    stackPointer->size = s;
    stackPointer->top = -1;
    stackPointer->arr = (int *)malloc(s * sizeof(int));
    printf("***Stack creation is completed***\n");

    push(stackPointer, 7);
    push(stackPointer, 4);
    push(stackPointer, 45);
    push(stackPointer, 34);
    push(stackPointer, 23);
    push(stackPointer, 45);
    push(stackPointer, 12);
    push(stackPointer, 22);
    push(stackPointer, 67);

    printf("\nPrinting values from the stack\n");
    for (int i = 1; i <= stackPointer->top + 1; i++)
    {
        printf("The value at position of index %d  is %d\n", i, peek(stackPointer, i));
    }

    // if we want to have an specific value of any index
    printf("\nValue of an specific position\n");
    int p;
    printf("Enter position number \n");
    scanf("%d", &p);
    printf("The value at position of index %d  is %d\n", p, peek(stackPointer, p));

    printf("Stack's top element is %d\n", stackTop(stackPointer));
    printf("Stack's bottom element is %d\n", stackBottom(stackPointer));
    return 0;
}