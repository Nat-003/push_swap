#include "push_swap.h"
#include <stdio.h> // For printf to see results

void print_stack(t_stack *s, char *name)
{
    printf("Stack %s: ", name);
    for (int i = 0; i < s->size; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

int main()
{
    t_stack a;
    int values[] = {1,3,2}; // Your test numbers

    a.size = sizeof(values) / sizeof(values[0]);
    a.data = malloc(sizeof(int) * a.size);
    if (!a.data)
        return (1);
    float res = disorder(a.data,a.size);
    printf("disorder: %f\n",res);
    // Fill the stack
    for (int i = 0; i < a.size; i++)
        a.data[i] = values[i];

    print_stack(&a, "Before");
    
    bubble_sort(&a);
    
    print_stack(&a, "After");

    free(a.data);
    return (0);
}