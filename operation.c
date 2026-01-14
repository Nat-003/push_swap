#include "push_swap.h"
#include <unistd.h> // Ensure this is in your header or here for write()

void sa(t_stack *a)
{
    int tmp;
    if (a->size < 2)
        return ;
    tmp = a->data[0];
    a->data[0] = a->data[1];
    a->data[1] = tmp;
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    int tmp;
    if (b->size < 2)
        return ;
    tmp = b->data[0];
    b->data[0] = b->data[1];
    b->data[1] = tmp;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    int tmp;
    // Manual swap for a to avoid double printing sa/sb
    if (a->size >= 2)
    {
        tmp = a->data[0];
        a->data[0] = a->data[1];
        a->data[1] = tmp;
    }
    // Manual swap for b
    if (b->size >= 2)
    {
        tmp = b->data[0];
        b->data[0] = b->data[1];
        b->data[1] = tmp;
    }
    write(1, "ss\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
    int value;
    int i;
    if (b->size == 0)
        return ;
    value = b->data[0];
    i = 0;
    while (i < b->size - 1)
    {
        b->data[i] = b->data[i + 1];
        i++;
    }
    b->size--;    
    i = a->size;
    while (i > 0)
    {
        a->data[i] = a->data[i - 1];
        i--;
    }
    a->data[0] = value;
    a->size++;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    int value;
    int i;
    if (a->size == 0)
        return ;
    value = a->data[0];
    i = 0;
    while (i < a->size - 1)
    {
        a->data[i] = a->data[i + 1];
        i++;
    }
    a->size--;    
    i = b->size;
    while (i > 0)
    {
        b->data[i] = b->data[i - 1];
        i--;
    }
    b->data[0] = value;
    b->size++;
    write(1, "pb\n", 3);
}

void ra(t_stack *a)
{
    int first;
    int i;
    if (a->size < 2)
        return ;
    first = a->data[0];
    i = 0;
    while (i < a->size - 1)
    {
        a->data[i] = a->data[i + 1];
        i++;
    }
    a->data[a->size - 1] = first;
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    int first;
    int i;
    if (b->size < 2)
        return ;
    first = b->data[0];
    i = 0;
    while (i < b->size - 1)
    {
        b->data[i] = b->data[i + 1];
        i++;
    }
    b->data[b->size - 1] = first;
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    // Logic for ra without write
    int first;
    int i;
    if (a->size >= 2)
    {
        first = a->data[0];
        i = -1;
        while (++i < a->size - 1)
            a->data[i] = a->data[i + 1];
        a->data[a->size - 1] = first;
    }
    // Logic for rb without write
    if (b->size >= 2)
    {
        first = b->data[0];
        i = -1;
        while (++i < b->size - 1)
            b->data[i] = b->data[i + 1];
        b->data[b->size - 1] = first;
    }
    write(1, "rr\n", 3);
}

void rra(t_stack *a)
{
    int last;
    int i;
    if (a->size  < 2)
        return ;
    last = a->data[a->size -1];
    i = a->size -1;
    while (i > 0)
    {
        a->data[i] = a->data[i - 1];
        i--;
    }
    a->data[0] = last;
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    int last;
    int i;
    if (!b || b->size < 2)
        return ;
    last = b->data[b->size - 1];
    i = b->size - 1;
    while (i > 0)
    {
        b->data[i] = b->data[i - 1];
        i--;
    }
    b->data[0] = last;
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    // Logic for rra without write
    int last;
    int i;
    if (a->size >= 2)
    {
        last = a->data[a->size - 1];
        i = a->size;
        while (--i > 0)
            a->data[i] = a->data[i - 1];
        a->data[0] = last;
    }
    // Logic for rrb without write
    if (b->size >= 2)
    {
        last = b->data[b->size - 1];
        i = b->size;
        while (--i > 0)
            b->data[i] = b->data[i - 1];
        b->data[0] = last;
    }
    write(1, "rrr\n", 4);
}