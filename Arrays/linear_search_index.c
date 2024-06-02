// linear search index on array

#include <stdio.h>
void display();
int checkElement();

int main()
{
    int num;
    printf("Enter a no. ");
    scanf("%d", &num);
    int arr[] = {2, 5, 3, 6, 7, 1};
    int size = sizeof(arr) / sizeof(int);
    display(arr, 6);

    int returnValue = checkElement(arr, num, size);

    if (returnValue != 1)
        printf("No, This element is not in this array \n");
    return 0;
}
void display(int arr[], int capicity)
{
    for (int i = 0; i < capicity; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int checkElement(int arr[], int num, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            printf("The element's index no. is %d \n", i);
            return 1;
        }
    }
}