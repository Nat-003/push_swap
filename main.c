#include "push_swap.h"
#include <stdio.h> // For printf to see results

void print_stack(t_stack *s, char *name)
{
    printf("Stack %s: ", name);
    for (int i = 0; i < s->size; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

void select_algorithm(float d, t_stack *a,t_ops *ops)
{
    if (d < 0.30f)
    {
        bubble_sort(a,ops);
    }
    else if (d < 0.50f)
    {
        printf("O(nVn)\n");
        bubble_sort(a,ops);
    }
    else
    {
        printf("n log n\n");
        bubble_sort(a,ops);
    }
}
int total_operation(t_ops *ops)
{
    int sum;
    sum = 0;
    printf("sa  : %d\n", ops->sa);
    printf("sb  : %d\n", ops->sb);
    printf("ss  : %d\n", ops->ss);
    printf("ra  : %d\n", ops->ra);
    printf("rb  : %d\n", ops->rb);
    printf("rr  : %d\n", ops->rr);
    printf("rra : %d\n", ops->rra);
    printf("rrb : %d\n", ops->rrb);
    printf("rrr : %d\n", ops->rrr);
    sum = ops->sa + ops->sb + ops->ss + \
          ops->ra + ops->rb + ops->rr + \
          ops->rra + ops->rrb + ops->rrr;
    return (sum);
}
int main(int ac, char **av)
{
    t_stack a;
    t_stack b;

    t_ops ops = {0};

    if (ac < 2)
        return (1);

    a.size = ac - 1;
    a.data = malloc(sizeof(int) * a.size);
    if (!a.data)
        return (1);

    for (int i = 0; i < a.size; i++)
        a.data[i] = atoi(av[i + 1]);

    print_stack(&a, "Before");

    float res = disorder(a.data, a.size);
    printf("disorder: %f\n", res);

    select_algorithm(res, &a, &ops);
    int total_ops = total_operation(&ops);

    printf(" total operation :%d\n",total_ops);
    print_stack(&a, "After");

    free(a.data);
    return (0);
}
