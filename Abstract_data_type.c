// Absract Data Type ka use 
// Abstract Data Type (ADT) एक programming concept है
#include <stdio.h>
#include <stdlib.h>
void creatArray();
// void show();
void setValue();

struct myarray
{
    int totalSize;
    int usedSize;
    int *ptr;
};

int main()
{
    struct myarray marks;
    int arrayTotalSize, useSize;
    printf("enter a no. for array size = ");
    scanf("%d", &arrayTotalSize);
    printf("enter no. do you want to use the size of array = ");
    scanf("%d", &useSize);

    creatArray(&marks, arrayTotalSize, useSize);
    printf("setValue running\n");
    setValue(&marks);
    // printf("show running\n");
    // show(&marks);

    return 0;
}
void creatArray(struct myarray *a, int arrayTotalSize, int useSize)
{
    (*a).totalSize = arrayTotalSize;
    (*a).usedSize = useSize;
    int *ptr = (int *)malloc(arrayTotalSize * sizeof(int));
    free(ptr);
    // 2nd tarika isko linkhne ka
    // a->totalSize = arrayTotalSize;
    // a->usedSize = useSize;
    // a->ptr = (int *)malloc(arrayTotalSize * sizeof(int));
    free(ptr);
}

void setValue(struct myarray *a)
{
    int n;
    for (int i = 0; i < (*a).usedSize; i++)
    {
        printf("Enter %d element  ", i);
        scanf("%d", &n);
        (*a).ptr[i] = n;
    }

    for (int i = 0; i < (*a).usedSize; i++)
    {
        printf("%d\n", (*a).ptr[i]);
    }
}

// void show(struct myarray *a)
// {
//     for (int i = 0; i < (*a).usedSize; i++)
//     {
//         printf("%d\n", (*a).ptr[i]);
//     }
// }

/* Defination of this program :-

sbse pahle struct function ka use krke totalsize , usedSize and *ptr variable bnaye jisse wo gloval variables bn jaye
totalSize variable program me memory ki size bdane se phle use hone wali puri memory ko btata h aur usedSize
use hone wali memory ko

in main function:-
main function me marks naam ka ek struct variable bnaya jata h
arrayTotalSize variable ram me extra mamroy ko reserve krne ke liye future ke liye aur useSize variable ram me
use hone wali mamroy ko reserve krne ke liye , jo ki user's input base h
phir 
(creatArray function ka use ram me memory ko dynamicly use krne ke liye bnaya ja rha )
creatArray ek function ko call kiya jisme struct myArray marks ke address ko paas kiya  , arrayTotalSize aur
useSize ko paas kiya
(struct me address ko liya jata h variable ko de-refrence krne ke liye aur ek pointer(*)me liya jata h )

*/