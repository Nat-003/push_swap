/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:25:06 by nappasam          #+#    #+#             */
/*   Updated: 2026/02/21 17:33:16 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_program *p)
{
	int	last;
	int	i;

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

void	rrb(t_program *p)
{
	int	last;
	int	i;

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

void	rrr(t_program *p)
{
	int	last;
	int	i;

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
