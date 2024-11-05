/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miss_act2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:38:34 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 07:47:18 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_stack(t_node_stack *stack)
{
	while (stack != NULL)
	{
		if ((*stack).cheapest == true)
		{
			(*stack).cheapest = false;
		}
		stack = (*stack).next;
	}
}

void	check_5con(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	if (!((a)||(b)))
	{
		handle_error(a);
		handle_error(b);
	}
	if (stack_len(*a) == 3 && stack_len(*b) < 3)
	{
		while (*b)
		{
			pa(b, a);
		}
		*b = NULL;
		if (total_len <= 5)
		{
			if ((*a)->tar_index > (*a)->next->tar_index)
			{
				sa(a);
			}
		}
	}
}
