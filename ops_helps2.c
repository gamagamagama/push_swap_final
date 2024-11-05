/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_helps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:46:26 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 07:49:16 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psafch(t_node_stack **a, t_node_stack **b,
				size_t total_len, size_t flag)
{
	prepare_stack_a(a);
	prepare_stack_b(a, b, total_len);
	set_total_price(b);
	set_cheapest(*b, total_len, flag);
}

void	process_stack(t_node_stack **stack, size_t median)
{
	t_node_stack	*current;

	current = *stack;
	while (current)
	{
		if (current->tar_index == 0)
		{
			mttp(stack, current, median);
			if (current->index == current->tar_index)
			{
				break ;
			}
		}
		current = current->next;
	}
}
