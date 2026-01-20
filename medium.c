#include "push_swap.h"

/* Using your custom sqrt to avoid math.h */
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
    return ((int)i - 1); // Return floor of sqrt if not perfect
}

/* Your original functions preserved */
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

/* The fixed Bucket Sort logic */
void bucket_sort(t_stack *a, t_stack *b, t_ops *ops)
{
    int *copy;
    int original_size = a->size;
    int i, j, bucket_count, bucket_size, current_min, current_max;

    copy = copy_arr(a);
    sort_array(copy, original_size);

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
    bucket_count = ft_sqrt(original_size);
    if (bucket_count == 0) bucket_count = 1;
    bucket_size = original_size / bucket_count;
    
    current_min = 0;
    current_max = bucket_size - 1;

    // 4. Push Buckets A -> B
    i = 0;
    while (i < bucket_count)
    {
        if (i == bucket_count - 1) // Ensure last bucket covers everything
            current_max = original_size - 1;

        while (still_in_bucket(a, current_min, current_max))
        {
            if (a->data[0] >= current_min && a->data[0] <= current_max)
                pb(a, b, ops);
            else
                ra(a, ops);
        }
        current_min += bucket_size;
        current_max += bucket_size;
        i++;
    }

    // 5. Back to A: Find max in B and push
    while (b->size > 0)
    {
        int max_val = find_max_value(b);
        int pos = find_position(b, max_val);
        while (pos != 0)
        {
            if (pos <= b->size / 2)
                rb(b, ops);
            else
                rrb(b, ops);
            pos = find_position(b, max_val);
        }
        pa(a, b, ops);
    }

    // 6. THE FIX: Convert indices back to original values
    // Now that stack A is sorted (0, 1, 2, 3...), we replace those 
    // positions with the actual numbers from our copy.
    i = 0;
    while (i < a->size)
    {
        int index_stored = a->data[i];
        a->data[i] = copy[index_stored];
        i++;
    }

    // 7. Cleanup
    free(copy);
}
