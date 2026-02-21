/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappasam <nappasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:20:41 by nappasam          #+#    #+#             */
/*   Updated: 2026/02/21 17:33:30 by nappasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_program *p)
{
	int	tmp;

	if (p->a->size < 2)
		return ;
	tmp = p->a->data[0];
	p->a->data[0] = p->a->data[1];
	p->a->data[1] = tmp;
	p->ops->sa++;
	if (!p->config->bench)
		write(1, "sa\n", 3);
}

void	sb(t_program *p)
{
	int	tmp;

	if (p->b->size < 2)
		return ;
	tmp = p->b->data[0];
	p->b->data[0] = p->b->data[1];
	p->b->data[1] = tmp;
	p->ops->sb++;
	if (!p->config->bench)
		write(1, "sb\n", 3);
}

void	ss(t_program *p)
{
	int	tmp;

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
