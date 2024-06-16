#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *sp)
{
    if (sp->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

void push(struct stack *sp, char element)
{
    if (isFull(sp))
        printf("Stack overflow ! , Can't push any %c element\n", element);
    else
    {
        sp->top++; // top incrementation is important
        sp->arr[sp->top] = element;
    }
}

char pop(struct stack *sp)
{
    if (isEmpty(sp))
        printf("Stack is Empty, Can't pop any element\n");
    else
    {
        char value = sp->arr[sp->top]; // for which element is poped
        sp->top--;
        return value;
    }
}

int matching(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(sp, '(');
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
                return 0;
            pop(sp);
        }
    }
    if (isEmpty(sp))
        return 1;
    return 0;
}
int main()
{
    char *exp = "(2+3))";
    if (matching(exp))
        printf("Matching\n");
    else
        printf("Not Matching\n");
}