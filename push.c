/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:51:07 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 09:56:11 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node_stack **from, t_node_stack **to)
{
	t_node_stack	*pushed;

	if (!*from)
		return ;
	pushed = *from;
	*from = (**from).next;
	if (*from)
	{
		(**from).prev = NULL;
	}
	(*pushed).prev = NULL;
	if (!*to)
	{
		*to = pushed;
		(*pushed).next = NULL;
	}
	else
	{
		(**to).prev = pushed;
		(*pushed).next = *to;
		*to = (**to).prev;
	}
}

void	pa(t_node_stack **b, t_node_stack **a)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	pb(t_node_stack **a, t_node_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
