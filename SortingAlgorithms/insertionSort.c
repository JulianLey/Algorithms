#include <stdio.h>


void insertionSort(int* array, int n)
{


    if (n > 1)
    {
        insertionSort(array, n - 1);
        int x = array[n-1];
        int j = n-2;
        while (j >= 0 && array[j] > x)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = x;
    }
}

int main()
{
    //Example

    int array[] = {2, 1, 8, 3, 7, 1, 2, 1, 3, 4, 2, 5, 4, 6, 0, 9, 8, 7, -1, -5};
    int target = 4;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    insertionSort(array, arrayLength);
    

    printf("{%d, ", *array);
    for (int i = 1; i < arrayLength - 1; i++)
    {
        printf("%d, ", *(array + i));
    }
    printf("%d}", array[arrayLength - 1]);


    return 0;
}