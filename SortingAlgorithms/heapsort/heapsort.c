#include <stdio.h>
#include <math.h>

int iLeftChild(int i)
{
    return 2 * i + 1;
}

int iRightChild(int i)
{
    return 2 * i + 2;
}

int iParent(int i)
{
    return (i - 1) / 2;
}

void siftDown(int* array, int root, int end)
{
    while (iLeftChild(root) < end)
    {
        int child = iLeftChild(root);
        
        if (child + 1 < end && array[child] < array[child + 1])
        {
            child = child + 1;
        }

        if (array[root] < array[child])
        {
            int temp = array[root];
            array[root] = array[child];
            array[child] = temp;
            root = child;
        }
        else
        {
            return;
        }
    }
}

void heapify(int* array, int count)
{
    int start = iParent(count - 1) + 1;

    while (start > 0)
    {
        start = start - 1;
        siftDown(array, start, count);
    }
}

void heapsort(int* array, int count)
{
    heapify(array, count);

    int end = count;
    
    while (end > 1)
    {
        end--;
        int temp = array[end];
        array[end] = array[0];
        array[0] = temp;

        siftDown(array, 0, end);
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

    int arrayLength1 = sizeof(array1) / sizeof(array1[0]);

    heapsort(array1, arrayLength1);

    printArray(array1, arrayLength1);


    return 0;
}