#include "push_swap.h"
#include <unistd.h>

void sa(t_program *p)
{
	int tmp;

	if (p->a->size < 2)
		return ;
	tmp = p->a->data[0];
	p->a->data[0] = p->a->data[1];
	p->a->data[1] = tmp;
	p->ops->sa++;
	if (!p->config->bench)
		write(1, "sa\n", 3);
}

void sb(t_program *p)
{
	int tmp;

	if (p->b->size < 2)
		return ;
	tmp = p->b->data[0];
	p->b->data[0] = p->b->data[1];
	p->b->data[1] = tmp;
	p->ops->sb++;
	if (!p->config->bench)
		write(1, "sb\n", 3);
}

void ss(t_program *p)
{
	int tmp;

	if (p->a->size >= 2)
	{
		tmp = p->a->data[0];
		p->a->data[0] = p->a->data[1];
		p->a->data[1] = tmp;
	}
	if (p->b->size >= 2)
	{
		tmp = p->b->data[0];
		p->b->data[0] = p->b->data[1];
		p->b->data[1] = tmp;
	}
	p->ops->ss++;
	if (!p->config->bench)
		write(1, "ss\n", 3);
}

void pa(t_program *p)
{
	int i;

	if (p->b->size == 0)
		return ;
	i = p->a->size;
	while (i > 0)
	{
		p->a->data[i] = p->a->data[i - 1];
		i--;
	}
	p->a->data[0] = p->b->data[0];
	p->a->size++;
	i = 0;
	while (i < p->b->size - 1)
	{
		p->b->data[i] = p->b->data[i + 1];
		i++;
	}
	p->b->size--;
	p->ops->pa++;
	if (!p->config->bench)
		write(1, "pa\n", 3);
}

void pb(t_program *p)
{
	int i;

	if (p->a->size == 0)
		return ;
	i = p->b->size;
	while (i > 0)
	{
		p->b->data[i] = p->b->data[i - 1];
		i--;
	}
	p->b->data[0] = p->a->data[0];
	p->b->size++;
	i = 0;
	while (i < p->a->size - 1)
	{
		p->a->data[i] = p->a->data[i + 1];
		i++;
	}
	p->a->size--;
	p->ops->pb++;
	if (!p->config->bench)
		write(1, "pb\n", 3);
}

void ra(t_program *p)
{
	int first;
	int i;

	if (p->a->size < 2)
		return ;
	first = p->a->data[0];
	i = 0;
	while (i < p->a->size - 1)
	{
		p->a->data[i] = p->a->data[i + 1];
		i++;
	}
	p->a->data[p->a->size - 1] = first;
	p->ops->ra++;
	if (!p->config->bench)
		write(1, "ra\n", 3);
}

void rb(t_program *p)
{
	int first;
	int i;

	if (p->b->size < 2)
		return ;
	first = p->b->data[0];
	i = 0;
	while (i < p->b->size - 1)
	{
		p->b->data[i] = p->b->data[i + 1];
		i++;
	}
	p->b->data[p->b->size - 1] = first;
	p->ops->rb++;
	if (!p->config->bench)
		write(1, "rb\n", 3);
}

void rr(t_program *p)
{
	int first;
	int i;

	if (p->a->size >= 2)
	{
		first = p->a->data[0];
		i = -1;
		while (++i < p->a->size - 1)
			p->a->data[i] = p->a->data[i + 1];
		p->a->data[p->a->size - 1] = first;
	}
	if (p->b->size >= 2)
	{
		first = p->b->data[0];
		i = -1;
		while (++i < p->b->size - 1)
			p->b->data[i] = p->b->data[i + 1];
		p->b->data[p->b->size - 1] = first;
	}
	p->ops->rr++;
	if (!p->config->bench)
		write(1, "rr\n", 3);
}

void rra(t_program *p)
{
	int last;
	int i;

	if (p->a->size < 2)
		return ;
	last = p->a->data[p->a->size - 1];
	i = p->a->size - 1;
	while (i > 0)
	{
		p->a->data[i] = p->a->data[i - 1];
		i--;
	}
	p->a->data[0] = last;
	p->ops->rra++;
	if (!p->config->bench)
		write(1, "rra\n", 4);
}

void rrb(t_program *p)
{
	int last;
	int i;

	if (p->b->size < 2)
		return ;
	last = p->b->data[p->b->size - 1];
	i = p->b->size - 1;
	while (i > 0)
	{
		p->b->data[i] = p->b->data[i - 1];
		i--;
	}
	p->b->data[0] = last;
	p->ops->rrb++;
	if (!p->config->bench)
		write(1, "rrb\n", 4);
}

void rrr(t_program *p)
{
	int last;
	int i;

	if (p->a->size >= 2)
	{
		last = p->a->data[p->a->size - 1];
		i = p->a->size - 1;
		while (i > 0)
		{
			p->a->data[i] = p->a->data[i - 1];
			i--;
		}
		p->a->data[0] = last;
	}
	if (p->b->size >= 2)
	{
		last = p->b->data[p->b->size - 1];
		i = p->b->size - 1;
		while (i > 0)
		{
			p->b->data[i] = p->b->data[i - 1];
			i--;
		}
		p->b->data[0] = last;
	}
	p->ops->rrr++;
	if (!p->config->bench)
		write(1, "rrr\n", 4);
}
