/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:55 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 09:55:06 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot(t_node_stack **stack)
{
	t_node_stack	*last_node;

	if (!*stack || !(**stack).next)
	{
		return ;
	}
	last_node = find_last_node(*stack);
	(*last_node).next = *stack;
	(*(*last_node).prev).next = NULL;
	(*last_node).prev = NULL;
	(**stack).prev = last_node;
	*stack = (**stack).prev;
}

void	rra(t_node_stack **a)
{
	rev_rot(a);
	ft_putstr("rra\n");
}

void	rrb(t_node_stack **b)
{
	rev_rot(b);
	ft_putstr("rrb\n");
}

void	rrr(t_node_stack **a, t_node_stack **b)
{
	rev_rot(a);
	rev_rot(b);
	ft_putstr("rrr\n");
}
