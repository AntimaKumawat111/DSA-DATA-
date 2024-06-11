
#include <stdio.h>
void triversalArray();
int insertIndex(int array[], int index, int element, int capacity, int size);

int main()
{
    int array[100] = {2, 4, 5, 5, 3};
    int index, element;
    printf("Index number : ");
    scanf("%d", &index);
    printf("Element number : ");
    scanf("%d", &element);
    int size = 5;
    triversalArray(array, size);
    insertIndex(array, index, element, 100, size);
    size++;
    triversalArray(array, size);

    return 0;
}
void triversalArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

int insertIndex(int array[], int index, int element, int capacity, int size)
{
    if (size >= capacity)
        return -1;

    for (int i = size - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = element;
    return 1;
}
