#include "push_swap.h"

void bubble_sort(t_stack *a)
{
    int i = 0;
int j;

while (i < a->size)
{
    j = 0;
    while (j < a->size - 1)
    {
        if (a->data[0] > a->data[1])
            sa(a);
        ra(a);
        j++;
    }
    ra(a);
    i++;
}
}


