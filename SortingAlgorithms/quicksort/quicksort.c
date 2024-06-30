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



int main()
{
    //Example

    int array[] = {2, 1, 8, 3, 7, 1, 2, 1, 3, 4, 2, 5, 4, 6, 0, 9, 8, 7, -1, -5};
    int target = 4;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    quicksortLomuto(array, 0, arrayLength - 1);
    

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