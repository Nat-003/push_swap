#include "push_swap.h"
#include <stdio.h>

void bubble_sort(t_program *p)
{
    int i = 0;
    int j;
    int swapped;

    while (i < p->a->size -1)
    {
        swapped = 0;
        j = 0;
        while (j < p->a->size - 1)
        {
            if (p->a->data[0] > p->a->data[1]) 
                {
                    sa(p);
                    swapped = 1;
                }
            ra(p);
            j++;
        }
        ra(p);
        if (swapped == 0)
            return ;
        i++;
    }
}

