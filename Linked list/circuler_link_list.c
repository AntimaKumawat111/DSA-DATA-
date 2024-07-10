#include <stdio.h>
#include <stdlib.h>
struct node *insertionAtFirst();
struct node
{
    int data;
    struct node *next;
};

void triverseLinkedList(struct node *head)
{
    struct node *p = head;
    do
    {
        printf(" Element : %d\n", p->data);
        p = p->next;
    } while (p != head);
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    // memory reserve in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    // first link
    head->data = 5;
    head->next = second;

    // second link
    second->data = 6;
    second->next = third;

    // third link
    third->data = 7;
    third->next = fourth;
    
    // fourth link
    fourth->data = 8;
    fourth->next = fifth;
    
    // fifth link
    fifth->data = 9;
    fifth->next = head;

    // function call
    printf("Before insertion\n");
    triverseLinkedList(head);
    printf("After insertion\n");
    head = insertionAtFirst(head, 3);
    triverseLinkedList(head);

    return 0;
}

struct node *insertionAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head->next; // dusra pointer head ke next ko point krega jisse loop start ho payega 
    while (p->next != head)// or jb tk p ka next head nhi ho jata tb tk loop chalega 
    {
        p = p->next;
    }
    p->next = ptr;// p ke next ko ptr bna denge jisse memory me ek node jud jayega p ke aage
    ptr->data = data;
    ptr->next = head;// phir ptr ke next me head rkh denge jisse ptr ka next me head ki value aa jayegi
    head = ptr;// head ko ptr bnane se ptr ki value first value bn jayegi aur wo starting me add ho jayegi
    return head;
}
