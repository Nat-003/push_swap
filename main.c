#include "push_swap.h"
#include <stdio.h> // For printf to see results

void print_stack(t_stack *s, char *name)
{
    printf("Stack %s: ", name);
    for (int i = 0; i < s->size; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

void select_algorithm(float d, t_stack *a,t_stack *b,t_ops *ops)
{
    if (d < 0.30f)
    {
        bubble_sort(a,ops);
        printf("O(n2)");
    }
    else if (d < 0.50f)
    {
        printf("O(nVn)\n");
        bucket_sort(a,b,ops);
    }
    else
    {
        printf("n log n\n");
        bucket_sort(a,b,ops);
    }
}


int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_ops ops= {0};
	t_config config = parser(av,&a);
	innit_stack_b(&b,a.size);
    float d = disorder(a.data,a.size);
    // printf("--- BEFORE SORTING ---\n");
    // print_stack(&a, "A");
    // print_stack(&b, "B");
    // printf("----------------------\n\n");

	if (config.simple)
    {
		bubble_sort(&a,&ops);
    }
	else if (config.medium)
    {
		bucket_sort(&a,&b,&ops);
    }
	else if (config.complex)
    {
		radix_lsd_sort(&a,&b,&ops);
    }
    else if (config.adaptative)
    {
        select_algorithm(d,&a,&b,&ops);
    }
    
	bench(&ops,d,&config);
    // printf("\n--- AFTER SORTING ---\n");
    // print_stack(&a, "A");
    // print_stack(&b, "B");
    // printf("---------------------\n");
}
