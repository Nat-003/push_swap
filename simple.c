#include "push_swap.h"
#include <stdio.h>
void bubble_sort(t_stack *a,t_ops *ops)
{
    int i = 0;
    int j;
    int swapped;

while (i < a->size)
{
    swapped = 0;
    j = 0;
    while (j < a->size - 1)
    {
        if (a->data[0] > a->data[1]) 
            {
                sa(a,ops);
                swapped = 1;
            }
        ra(a,ops);
        j++;
    }
    ra(a,ops);
    if (swapped == 0)
        return ;
    i++;
}
}


