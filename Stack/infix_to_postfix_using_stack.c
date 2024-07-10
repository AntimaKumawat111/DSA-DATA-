#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

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

int isOpreator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    return 0;
}

int precidence(char ch)// 
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
        
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix traversal
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (!isOpreator(infix[i]))// agr infix [i] ek operator nhi h tb 
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else 
        {
            if (precidence(infix[i]) > precidence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp);
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s\n", infixToPostfix(infix));

    return 0;
}
