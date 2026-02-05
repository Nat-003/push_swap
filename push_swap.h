#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>
#include <stdio.h> 
#include <limits.h>

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

typedef struct s_config
{
	int simple;
	int medium;
	int complex;
	int adaptative;
	int bench;
} t_config;

// helper function
void innit_stack_b(t_stack *b,int size);
void error_exit();
// parser
t_config parser(char **av,t_stack *a);

/* Swap operations */
void    sa(t_stack *a, t_ops *ops);
void    sb(t_stack *b, t_ops *ops);
void    ss(t_stack *a, t_stack *b, t_ops *ops);

int check_flags(char **av,t_config *config);

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

// bench
void bench(t_ops *ops, float d, t_config *config);

// adaptive 
void select_algorithm(float d, t_stack *a,t_stack *b,t_ops *ops);

// void bubble_sort(t_stack *a, t_ops *ops);
void bubble_sort(t_stack *a,t_ops *ops);

// bucket sort O(nVn)
void bucket_sort(t_stack *a, t_stack *b, t_ops *ops);

// radix sort
void radix_ops(t_stack *a, t_stack *b, int n, int bit, t_ops *ops);
void radix_lsd_sort(t_stack *a, t_stack *b, t_ops *ops);

#endif