#include "push_swap.h"

int *copy_stack(t_stack *a)
{
    int *tmp;
    int i;

    tmp = malloc(sizeof(int) * a->size);
    if (!tmp)
        error_exit();
    i = 0;
    while (i < a->size)
    {
        tmp[i] = a->data[i];
        i++;
    }
    return tmp;
}
int get_pos(int *tmp, int size, int i)
{
    int j;
    int pos;

    pos = 0;
    j = 0;
    while (j < size)
    {
        if (tmp[j] < tmp[i])
            pos++;
        j++;
    }
    return pos;
}

int *compress_stack(t_stack *a)
{
    int *tmp;
    int *map;
    int i;

    tmp = copy_stack(a);
    map = malloc(sizeof(int) * a->size);
    if (!map)
        error_exit();
    i = 0;
    while (i < a->size)
    {
        map[get_pos(tmp, a->size, i)] = tmp[i];
        a->data[i] = get_pos(tmp, a->size, i);
        i++;
    }
    free(tmp);
    return map;
}

int get_max_bit(int max)
{
    int bits;

    bits = 0;
    while ((1 << bits) <= max)
        bits++;
    return bits - 1;
}

void radix_lsd_sort(t_stack *a, t_stack *b, t_ops *ops)
{
    int *map;
    int n;
    int max;
    int max_bit;
    int bit;

    n = a->size;
    if (n <= 1)
        return;
    map = compress_stack(a);
    max = n - 1;
    max_bit = get_max_bit(max);
    bit = 0;
    while (bit <= max_bit)
    {
        radix_ops(a, b, n, bit, ops);
        bit++;
    }
    int i = 0;
    while (i < n)
    {
        a->data[i] = map[a->data[i]];
        i++;
    }
    free(map);
}
