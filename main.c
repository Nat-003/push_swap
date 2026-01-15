#include "push_swap.h"
#include <stdio.h> // For printf to see results

void print_stack(t_stack *s, char *name)
{
    printf("Stack %s: ", name);
    for (int i = 0; i < s->size; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

void select_algorithm(float d, t_stack *s,t_ops *ops)
{
    if (d < 0.30f)
    {
        bubble_sort(s,ops);
    }
    else if (d < 0.50f)
    {
        printf("O(nVn)\n");
        bubble_sort(s,ops);
    }
    else
    {
        printf("n log n\n");
        bubble_sort(s,ops);
    }
}
int main(int ac, char **av)
{
    t_stack a;


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
    printf("%d",ops.ra);
    print_stack(&a, "After");

    free(a.data);
    return (0);
}
