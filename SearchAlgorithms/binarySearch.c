#include <stdio.h>

int binarySearch (int* array, int size, int target)
{
    int left = 0;
    int right = size-1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (array[middle] < target)
        {
            left = middle + 1;
        }
        else if (array[middle] > target)
        {
            right = middle -1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}


int main()
{
    //Example

    int array[] = {1, 2, 3, 4, 5, 7, 9};
    int target = 4;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    int result = binarySearch(array, arrayLength, target);
    printf("Result = %d\n", result);

    return 0;
}