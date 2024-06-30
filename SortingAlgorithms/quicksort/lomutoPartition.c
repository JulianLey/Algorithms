#include "partition.h"

int lomutoPartition(int* array, int low, int high)
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