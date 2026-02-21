#include "push_swap.h"
#include <stdio.h> // For printf to see results

void print_stack(t_stack *s, char *name)
{
    printf("Stack %s: ", name);
    for (int i = 0; i < s->size; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

void select_algorithm(float d, t_program *p)
{
    if (d < 0.30f)
    {
        bubble_sort(p);
    }
    else if (d < 0.50f)
    {
        bucket_sort(p);
    }
    else
    {
        radix_lsd_sort(p);
    }
}
void set_bench(t_program *p, float d)
{
	if (p->config->simple && p->config->bench)
    {
		bubble_sort(p);
		bench(p->ops,d,p->config);
    }
	else if (p->config->medium && p->config->bench)
    {
		bucket_sort(p);
		bench(p->ops,d,p->config);
    }
	else if (p->config->complex && p->config->bench)
    {
		radix_lsd_sort(p);
		bench(p->ops,d,p->config);;
    }
    else if (p->config->adaptative && p->config->bench)
    {
        select_algorithm(d,p);
		bench(p->ops,d,p->config);
    }
}

void set_config(t_program *p, float d)
{
	if (p->config->bench)
    {
		set_bench(p,d);
    }
	else if (p->config->simple)
	{
		bubble_sort(p);
	}
	else if (p->config->medium)
    {
		bucket_sort(p);
    }
	else if (p->config->complex)
    {
		radix_lsd_sort(p);
    }
    else if (p->config->adaptative)
    {
        select_algorithm(d,p);
    }
}
int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_ops ops= {0};
	t_config config = parser(av,&a);
    t_program p;
	innit_stack_b(&b,a.size);
    float d = disorder(a.data,a.size);
    p.a = &a;
    p.b = &b;
    p.ops = &ops;
    p.config = &config;
    // printf("--- BEFORE SORTING ---\n");
    // print_stack(&a, "A");
    // print_stack(&b, "B");
    // printf("----------------------\n\n");
	set_config(&p, d);
		
//     printf("\n--- AFTER SORTING ---\n");
//     print_stack(&a, "A");
//     print_stack(&b, "B");
//     printf("---------------------\n");
}
