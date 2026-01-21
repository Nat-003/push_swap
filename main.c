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

// void select_algorithm(float d, t_stack *a,t_ops *ops)
// {
//     if (d < 0.30f)
//     {
//         bubble_sort(a,ops);
//     }
//     else if (d < 0.50f)
//     {
//         printf("O(nVn)\n");
//         bubble_sort(a,ops);
//     }
//     else
//     {
//         printf("n log n\n");
//         bubble_sort(a,ops);
//     }
// }
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
        return (0);

    // 1. Setup Stack A
    a.size = ac - 1;
    a.data = malloc(sizeof(int) * a.size);
    if (!a.data)
        return (1);
    for (int i = 0; i < a.size; i++)
        a.data[i] = atoi(av[i + 1]);

    // 2. Setup Stack B (Capacity is same as A, but current size is 0)
    b.data = malloc(sizeof(int) * a.size);
    if (!b.data)
    {
        free(a.data);
        return (1);
    }
    b.size = 0;

    // --- BEFORE ---
    printf("--- BEFORE SORTING ---\n");
    print_stack(&a, "A");
    print_stack(&b, "B");
    printf("----------------------\n\n");

    // 3. Sorting
    float res = disorder(a.data, a.size);
    printf("%f\n",disorder);
    select_algorithm(res, &a, &b, &ops);

    // --- AFTER ---
    printf("\n--- AFTER SORTING ---\n");
    print_stack(&a, "A");
    print_stack(&b, "B");
    printf("---------------------\n");
    
    printf("Total operations: %d\n", total_operation(&ops));

    // 4. Cleanup
    free(a.data);
    free(b.data);
    return (0);
}
