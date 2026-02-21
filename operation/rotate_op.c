/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:24:13 by nappasam          #+#    #+#             */
/*   Updated: 2026/02/21 17:33:27 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_program *p)
{
	int	first;
	int	i;

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

void	rb(t_program *p)
{
	int	first;
	int	i;

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

void	rr(t_program *p)
{
	int	first;
	int	i;

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
