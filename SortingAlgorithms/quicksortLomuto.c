#include <stdio.h>

int partition(int* array, int low, int high)
{
    int pivot = array[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    int temp = array[i];
    array[i] = array[high];
    array[high] = temp;
    return i;
}   

void quicksort(int* array, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int p = partition(array, low, high);
    
    quicksort(array, low, p - 1);
    quicksort(array, p + 1, high);
}



int main()
{
    //Example

    int array[] = {2, 1, 8, 3, 7, 1, 2, 1, 3, 4, 2, 5, 4, 6, 0, 9, 8, 7, -1, -5};
    int target = 4;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    quicksort(array, 0, arrayLength - 1);
    

    printf("{");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d", *(array + i));
        if (i < arrayLength - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");


    return 0;
}