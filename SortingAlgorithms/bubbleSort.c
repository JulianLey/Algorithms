#include <stdio.h>

/*
#####################################################
#       Time Complexity:                O(n^2)      #
#       Best Case Time Complexity:      O(n)        #
#       Space Complexity:               O(1)        #
#####################################################
*/

void bubbleSort(int* array, int n)
{    
    while(n > 1)
    {
        int newN = 0;
        for (int i = 1; i < n ; i++)
        {
            if (array[i - 1] > array [i])
            {
                int temp = array[i-1];
                array[i - 1] = array[i];
                array[i] = temp;
                newN = i;
            }
        }
        n = newN;
    }
}


int main()
{
    //Example

    int array[] = {2, 1, 8, 3, 7, 1, 2, 1, 3, 4, 2, 5, 4, 6, 0, 9, 8, 7, -1, -5};
    int target = 4;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, arrayLength);
    

    printf("{%d, ", *array);
    for (int i = 1; i < arrayLength - 1; i++)
    {
        printf("%d, ", *(array + i));
    }
    printf("%d}", array[arrayLength - 1]);


    return 0;
}