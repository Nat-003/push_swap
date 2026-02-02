#include "push_swap.h"

void innit_stack_b(t_stack *b,int size)
{
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		error_exit();
	b->size = 0;
}
void radix_ops(t_stack *a, t_stack *b, int n, int bit, t_ops *ops)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (((a->data[0] >> bit) & 1) == 0)
            pb(a, b, ops);
        else
            ra(a, ops);
        i++;
    }
    while (b->size > 0)
        pa(a, b, ops);
}