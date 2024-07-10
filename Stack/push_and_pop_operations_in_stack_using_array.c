#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *sp)
{
    if (sp->top < 0)
        return 1;
    else
        return 0;
}

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *sp, int element)
{
    if (isFull(sp))
        printf("Stack overflow ! , Can't push any %d element\n", element);
    else
    {
        sp->top++; // top incrementation is important
        sp->arr[sp->top] = element;
    }
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
        printf("Stack is Empty, Can't pop any element\n");
    else
    {
        int value = sp->arr[sp->top]; // for which element is poped
        sp->top--;
        return value;
    }
}

int main()
{
    struct stack *stackPointer = (struct stack *)malloc(sizeof(struct stack));
    int stackSize, as;

    printf("Enter stack's size: ");
    scanf("%d", &stackSize);
    stackPointer->size = stackSize;
    stackPointer->top = -1; 
    stackPointer->arr = (int *)malloc(stackSize * sizeof(int));

    printf("Stack creation is commplete\n");
    printf("Empty : %d\n", isEmpty(stackPointer));
    printf("full  : %d\n", isFull(stackPointer));

    printf("After push an element\n");
    push(stackPointer, 576);
    push(stackPointer, 36);
    push(stackPointer, 26);
    push(stackPointer, 56);
    printf("Empty : %d\n", isEmpty(stackPointer));
    printf("full  : %d\n", isFull(stackPointer));

    printf("After pop a element\n");
    printf("Popped element : %d\n", pop(stackPointer));
    printf("Popped element : %d\n", pop(stackPointer));

    return 0;
}