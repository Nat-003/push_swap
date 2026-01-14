#include <stdio.h>
#include "push_swap.h"


float disorder(int *arr, int size)
{
    int i;
    int j;
    int mistakes = 0;
    int pairs = 0;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            pairs++;
            if (arr[i] > arr[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return ((double)mistakes / pairs);
}
