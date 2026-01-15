#include "push_swap.h"
#include <stdio.h>
void bubble_sort(t_stack *a,t_ops *ops)
{
    int i = 0;
int j;

while (i < a->size)
{
    j = 0;
    while (j < a->size - 1)
    {
        if (a->data[0] > a->data[1])
            sa(a,ops);
        ra(a,ops);
        j++;
    }

    ra(a,ops);
    i++;
}
}


