#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>

typedef struct s_ops
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
} t_ops;

typedef struct s_stack
{
    int *data;
    int size;
} t_stack;




/* Swap operations */
void    sa(t_stack *a, t_ops *ops);
void    sb(t_stack *b, t_ops *ops);
void    ss(t_stack *a, t_stack *b, t_ops *ops);

/* Push operations */
void    pa(t_stack *a, t_stack *b, t_ops *ops);
void    pb(t_stack *a, t_stack *b, t_ops *ops);

/* Rotate operations */
void    ra(t_stack *a, t_ops *ops);
void    rb(t_stack *b, t_ops *ops);
void    rr(t_stack *a, t_stack *b, t_ops *ops);

/* Reverse rotate operations */
void    rra(t_stack *a, t_ops *ops);
void    rrb(t_stack *b, t_ops *ops);
void    rrr(t_stack *a, t_stack *b, t_ops *ops);

/*disorder*/
float disorder(int *arr, int size);

// void bubble_sort(t_stack *a, t_ops *ops);
void bubble_sort(t_stack *a,t_ops *ops);
#endif