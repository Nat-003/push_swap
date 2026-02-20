#include "push_swap.h"

int ft_sqrt(int x)
{
    long i;

    if (x <= 0)
        return (0);
    if (x == 1)
        return (1);
    i = 1;
    while (i * i <= x)
    {
        if (i * i == x)
            return ((int)i);
        i++;
    }
    return ((int)i - 1);
}

int *copy_arr(t_stack *a)
{
    int i = 0;
    int *copy = malloc(sizeof(int) * a->size);
    if (!copy)
        return (NULL);
    while (i < a->size)
    {
        copy[i] = a->data[i];
        i++;
    }
    return (copy);
}

void sort_array(int *arr, int size)
{
    int i = 0, j, tmp;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

int still_in_bucket(t_stack *a, int min, int max)
{
    int i = 0;
    while (i < a->size)
    {
        if (a->data[i] >= min && a->data[i] <= max)
            return (1);
        i++;
    }
    return (0);
}

int find_max_value(t_stack *x)
{
    int i = 0;
    int current_max = x->data[0];
    while (i < x->size)
    {
        if (x->data[i] > current_max)
            current_max = x->data[i];
        i++;
    }
    return (current_max);
}

int find_position(t_stack *x, int max)
{
    int i = 0;
    while (i < x->size)
    {
        if (x->data[i] == max)
            return (i);
        i++;
    }
    return (-1);
}

void push_back_to_a(t_program *p)
{
	while (p->b->size > 0)
    {
        int max_val = find_max_value(p->b);
        int pos = find_position(p->b, max_val);
        while (pos != 0)
        {
            if (pos <= p->b->size / 2)
                rb(p);
            else
                rrb(p);
            pos = find_position(p->b, max_val);
        }
        pa(p);
    }
}
void innit_vars(int *bucket_count, int *bucket_size,int *current_min,int *current_max,int original_size)
{
	*bucket_count = ft_sqrt(original_size);
    if (*bucket_count == 0) *bucket_count = 1;
    *bucket_size = original_size / (*bucket_count);
    *current_min = 0;
    *current_max = *bucket_size - 1;
}
void push_a_to_b(t_program *p, int original_size)
{
	int i;
	int bucket_count;
	int bucket_size;
	int current_min;
	int current_max;

	innit_vars(&bucket_count,&bucket_size,&current_min,&current_max,original_size);
	i = 0;
    while (i < bucket_count)
    {
        if (i == bucket_count - 1) 
            current_max = original_size - 1;

        while (still_in_bucket(p->a, current_min, current_max))
        {
            if (p->a->data[0] >= current_min && p->a->data[0] <= current_max)
                pb(p);
            else
                ra(p);
        }
        current_min += bucket_size;
        current_max += bucket_size;
        i++;
    }
}
void change_value_to_indexes(t_stack *a, t_ops *ops,int original_size,int *copy)
{
	int i;
	int j;
	i = 0;
    while (i < original_size)
    {
        j = 0;
        while (j < original_size)
        {
            if (a->data[i] == copy[j])
            {
                a->data[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
}

/* The fixed Bucket Sort logic */
void bucket_sort(t_program *p)
{
    int *copy;
    int original_size = p->a->size;
    int i, j, bucket_count, bucket_size, current_min, current_max;

    copy = copy_arr(p->a);
	if (!copy_arr)
		return ; 

    sort_array(copy, original_size);
	change_value_to_indexes(p->a,p->ops,original_size,copy);
	push_a_to_b(p,original_size);
	push_back_to_a(p);
    i = 0;
    while (i < p->a->size)
    {
        int index_stored = p->a->data[i];
        p->a->data[i] = copy[index_stored];
        i++;
    }
    free(copy);
}
