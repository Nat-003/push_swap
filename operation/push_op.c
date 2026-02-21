/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:22:06 by nappasam          #+#    #+#             */
/*   Updated: 2026/02/21 17:33:24 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_program *p)
{
	int	i;

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

void	pb(t_program *p)
{
	int	i;

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
