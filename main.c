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
void set_bench(t_config *config,t_stack *a, t_stack *b,t_ops *ops, float d)
{
	if (config->simple && config->bench)
    {
		bubble_sort(a,ops);
		bench(ops,d,config);
    }
	else if (config->medium && config->bench)
    {
		bucket_sort(a,b,ops);
		bench(ops,d,config);
    }
	else if (config->complex && config->bench)
    {
		radix_lsd_sort(a,b,ops);
		bench(ops,d,config);
    }
    else if (config->adaptative && config->bench)
    {
        select_algorithm(d,a,b,ops);
		bench(ops,d,config);
    }
}

void set_config(t_config *config,t_stack *a, t_stack *b,t_ops *ops, float d)
{
	if (config->bench)
    {
		set_bench(config, a, b ,ops,d);
    }
	else if (config->simple)
	{
		bubble_sort(a,ops);
	}
	else if (config->medium)
    {
		bucket_sort(a,b,ops);
    }
	else if (config->complex)
    {
		radix_lsd_sort(a,b,ops);
    }
    else if (config->adaptative)
    {
        select_algorithm(d,a,b,ops);
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
	set_config(&config,&a,&b,&ops,d);
		
//     printf("\n--- AFTER SORTING ---\n");
//     print_stack(&a, "A");
//     print_stack(&b, "B");
//     printf("---------------------\n");
}
