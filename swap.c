/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:53:22 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 09:57:33 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node_stack **top)
{
	if (!*top || !(**top).next)
		return ;
	*top = (**top).next;
	(*(**top).prev).prev = *top;
	(*(**top).prev).next = (**top).next;
	if ((**top).next)
		(*(**top).next).prev = (**top).prev;
	(**top).next = (**top).prev;
	(**top).prev = NULL;
}

void	sa(t_node_stack **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_node_stack **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_node_stack **a, t_node_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
