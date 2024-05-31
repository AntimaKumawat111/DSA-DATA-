#include <stdio.h>
#include <stdlib.h>
void display();
void deletionValue();

int main()
{
    int arr[100] = {2, 5, 3, 6, 7, 1};
    int size = 6, index = 2;
    display(arr, size);
    deletionValue(arr, size, index);
    size--;
    display(arr, size);

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
void deletionValue(int arr[], int index, int size)
{

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
