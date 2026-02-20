#include "push_swap.h"

void innit_stack_b(t_stack *b,int size)
{
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		error_exit();
	b->size = 0;
}
void radix_ops(t_program *p, int n, int bit)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (((p->a->data[0] >> bit) & 1) == 0)
            pb(p);
        else
            ra(p);
        i++;
    }
    while (p->b->size > 0)
        pa(p);
}