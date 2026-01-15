#include "push_swap.h"

int  *copy_arr(t_stack *a)
{
    int i;
    int *copy;
    i = 0;
    copy = malloc(sizeof(int) * a->size);;
    while (i < a->size)
    {
        copy[i] = a->data[i];
        i++;
    }
    return (copy);
}

int	ft_sqrt(int x)
{
	long	i;

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
	return (0);
}
void sort(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size -1)
    {
        j = 0;
        while (j < size -1)
        {
            if (arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;            
            }
            j++;
        }
        i++;
    }
}
void bucket_sort(t_stack *a, t_stack *b, t_ops *ops)
{
    int *copy;
    int copy_size = a->size;
    int i;
    int j;
    int bucket_count;
    int bucket_size;

    i = 0;
    copy = copy_arr(a);
    bucket_count = ft_sqrt(a->size);
    bucket_size = a->size / bucket_count;
    sort(copy,copy_size);
    while (i < a->size )
    {
        j = 0;
        while (j < a->size)
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
    free(copy);
    i = 0;
    while (i < bucket_count)
    {
       
    }
    
}
