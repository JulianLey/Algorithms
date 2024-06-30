#include "partition.h"

int hoarePartition(int* array, int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {i++;}
        while (array[i] < pivot);

        do {j--;}
        while (array[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}