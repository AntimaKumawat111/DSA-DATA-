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

int match(char poped_element, char expi)
{
    if (poped_element == '{' && expi == '}')
        return 1;
    if (poped_element == '[' && expi == ']')
        return 1;
    if (poped_element == '(' && expi == ')')
        return 1;

    return 0;
}

int paranthisis_matching(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poped_element;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            push(sp, exp[i]);
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            poped_element = pop(sp);
            if (!match(poped_element, exp[i])) // agr ye dono match nhi krte h to 0 return ho jayega
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
        return 1;
    return 0;
}

int main()
{
    char *exp = "{3 + 7 [4 - 6 (2 *2 ) * 10 {2+3}]";

    if (paranthisis_matching(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced\n");

        return 0 ;
}
