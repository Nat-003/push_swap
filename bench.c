#include "push_swap.h"

int total_operation(t_ops *ops)
{
    int sum;

    sum = 0;
    printf("sa  : %d\n", ops->sa);
    printf("sb  : %d\n", ops->sb);
    printf("ss  : %d\n", ops->ss);
    printf("pa  : %d\n", ops->pa);
    printf("pb  : %d\n", ops->pb);
    printf("ra  : %d\n", ops->ra);
    printf("rb  : %d\n", ops->rb);
    printf("rr  : %d\n", ops->rr);
    printf("rra : %d\n", ops->rra);
    printf("rrb : %d\n", ops->rrb);
    printf("rrr : %d\n", ops->rrr);

    sum = ops->sa + ops->sb + ops->ss +
          ops->pa + ops->pb +
          ops->ra + ops->rb + ops->rr +
          ops->rra + ops->rrb + ops->rrr;

    return (sum);
}


char *adaptative_strat(t_config *config, float d)
{
    char *res;
    res = "";
    if (d < 0.30f)
       res = "Simple / O(n2)";
    else if (d < 0.50f)
        res = "Medium / O(nVn)";
    else
        res = "Complex / O(n log n)";
    return (res);
}
char *strat(t_config *config, float d)
{
    char *res;
    res = "";
    if (config->simple)
        res = "Simple O(n2)";
	else if (config->medium)
        res = "Medium O(nVn)";
	else if (config->complex)
        res = "Complex O(n log n)";
    else if (config->adaptative)
        res = adaptative_strat(config, d);
    
    return res;
}
void bench(t_ops *ops,float d, t_config *config)
{
   int res =  total_operation(ops);
   char *strategy = strat(config,d);
   printf("strategy: %s\n",strategy);
   printf("disorder: %f %% \n",d);
   printf("Total operations: %d\n", res);
}

