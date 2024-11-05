/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:52:07 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 09:56:42 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot(t_node_stack **stack)
{
	t_node_stack	*last_node;

	if (!*stack || !(**stack).next)
	{
		return ;
	}
	last_node = find_last_node(*stack);
	(*last_node).next = *stack;
	(*stack)->prev = last_node;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*(*last_node).next).next = NULL;
}

void	ra(t_node_stack **a)
{
	rot(a);
	ft_putstr("ra\n");
}

void	rb(t_node_stack **b)
{
	rot(b);
	ft_putstr("rb\n");
}

void	rr(t_node_stack **a, t_node_stack **b)
{
	rot(a);
	rot(b);
	ft_putstr("rr\n");
}

