#include <stdio.h>
#include "partition.h"

void quicksortLomuto(int* array, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int p = lomutoPartition(array, low, high);
    
    quicksortLomuto(array, low, p - 1);
    quicksortLomuto(array, p + 1, high);
}

void quicksortHoare(int* array, int low, int high)
{
    if (low < high)
    {
        int p = hoarePartition(array, low, high);

        quicksortHoare(array, low, p);
        quicksortHoare(array, p + 1, high);
    }
}

void printArray(int* array, int arrayLength)
{
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
}

int main()
{
    //Example

    int array1[] = {2, 1, 8, 3, 7, 1, 2, 1, 3, 4, 2, 5, 4, 6, 0, 9, 8, 7, -1, -5};
    int array2[] = {2, 1, 8, 3, 7, 1, 2, 1, 3, 4, 2, 5, 4, 6, 0, 9, 8, 7, -1, -5};

    int arrayLength1 = sizeof(array1) / sizeof(array1[0]);
    int arrayLength2 = sizeof(array2) / sizeof(array2[0]);

    quicksortLomuto(array1, 0, arrayLength1 - 1);
    quicksortHoare(array2, 0, arrayLength2 - 1);

    printArray(array1, arrayLength1);
    printArray(array2, arrayLength2);


    return 0;
}