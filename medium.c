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

int still_in_bucket(t_stack *a,int min, int max)
{
	int i;

	i = 0;
	while (i <a->size)
	{
		if (a->data[i] >= min && a->data[i] <= max)
			return (1);
		i++;
	}
	return (0);
}
void bucket_sort(t_stack *a, t_stack *b, t_ops *ops)
{
    int *copy;
    int copy_size = a->size;
    int i;
    int j;
    int bucket_count;
    int bucket_size;
	int current_min;
	int current_max;

    i = 0;
    copy = copy_arr(a);
    bucket_count = ft_sqrt(a->size);  // number of bucket
    bucket_size = a->size / bucket_count; // size of one bucket (ex: bucket 1 contain index 0 from 5)
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
	j= 0;
	current_min = 0;
	current_max = bucket_size;
    while (i < bucket_count)
    {
		while (still_in_bucket(a, current_min,current_max))
		{
		if (a->data[0] >= current_min && a->data[0] <= current_max)
		{
			pb(a,b,ops);
		}
		else
			ra(a,ops);
		j++;
		}	
     i++; 
    }
    
}
