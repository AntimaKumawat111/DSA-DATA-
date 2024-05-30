// Bianry search index on array

#include <stdio.h>
void display();
int binarySearch();

int main()
{
    int num;
    printf("Enter a no. ");
    scanf("%d", &num);
    int arr[] = {1, 2, 3, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    int returnValue = binarySearch(arr, num, size);
    //   printf("The value %d at the index no. is %d ",num , returnValue);
    if (returnValue == -1)
        printf("Not in this index ");
    else
        printf("The value %d at the index no. is %d ", num, returnValue);

    return 0;
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int num, int size)
{
    int lowValue = 0, highValue = size - 1;

    while (lowValue <= highValue)
    {
        int midValue = (lowValue + highValue) / 2;
        if (arr[midValue] == num)// agr mid ki value enter kiye gye num ke barabr hogi tb return hoga mid 
        {
            return midValue;
        }
        if (arr[midValue] < num)// agr mid ki value enter kiye gye num se chhoti hogi tb mid value + 1 ko low value bna denge or phir se check krenge 
        {
            lowValue = midValue + 1;
        }
        else
            highValue = midValue - 1;
    }
    return -1;
}
/* 3 , 5 , 7 , 9 , 12 , 34 , 45
low     high    mid     size
3       34      9       6
 check  9 > 3 || 9 < 45
 if 9 > 3
 9-1 ( mid - 1) = high
 else
 mid + 1 = low

 */