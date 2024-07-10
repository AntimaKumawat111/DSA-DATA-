#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int peek(struct node *top, int positionNumber)
{
    struct node *p = top;

    for (int i = 0; (i < positionNumber - 1 && p != NULL); i++)
        p = p->next;
    if (p != NULL) // When the loop has reached null it means it is the last step
        return p->data;
    else
        return -1;
}

int stackBottam(struct node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    if (top->next == NULL)
        return top->data;
    return -1;
}

int stackTop(struct node *top)
{
    return top->data;
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    // If dynamic memory is not displayed, it means that the memory is full.
    if (n == NULL)

        return 1;
    return 0;
}

struct node *push(struct node *top, int data)
{
    if (isFull(top))
        printf("Stack overflow !\n");
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow !\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int d = n->data;
        free(n);
        return d;
    }
}

void triverseLinkList(struct node *top)
{
    int i = 0;
    do
    {
        printf("Element %d : %d\n", i, top->data);
        top = top->next;
        i++;
    } while (top != NULL);
}

int main()
{
    struct node *top = NULL;

    printf("Before Push element\n");
    printf("Empty: %d\n", isEmpty(top));
    printf("Full : %d\n", isFull(top));

    top = push(top, 45);
    top = push(top, 48);
    top = push(top, 56);
    top = push(top, 90);

    printf("\nAfter Push element\n");
    printf("Empty: %d\n", isEmpty(top));
    printf("Full: %d\n", isFull(top));
    printf("The list is :-\n");
    triverseLinkList(top);

    printf("\nAfter Poped an element\n");
    int element = pop(&top);
    printf("Poped Element : %d\n", element);
    printf("The list is :-\n");
    triverseLinkList(top);
    printf("\n");
    int peekElement ;
    printf("Which index's number you want to peek\n");
    scanf("%d",&peekElement); 
    // we will start index number from 1 for user's help ------
    printf("The element is %d\n", peek(top, peekElement));// when the index number is not valid then return value is -1 
    printf("\n");
    printf("The stack's bottom number is %d\n", stackBottam(top));
    printf("The stack's top number is %d\n", stackTop(top));
}