#include <stdio.h>
void display();
int insertValue();

int main()
{
    int arr[100] = {2, 5, 3, 6, 7, 1};
    int size = 6, element = 4, index = 2;
    display(arr, size);
    insertValue(arr, size, element, index, 100);
    size++; // size ko function ke ander increase krke return nhi kr sakte 
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
int insertValue(int arr[], int size, int element, int index, int capicity)
{
    if (size >= capicity)
        return -1;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i]; // arr[i+1] means arr[i] ki jo bhi value h usme 1 index add ho jaye
    }
    arr[index] = element;
    return 1;
}
