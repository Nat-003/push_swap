#include "push_swap.h"

void innit_stack_b(t_stack *b,int size)
{
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		error_exit();
	b->size = 0;
}