/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:51:37 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 08:44:49 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_node_stack *stack)
{
	size_t	len_a;
	size_t	median;

	len_a = stack_len(stack);
	median = len_a / 2;
	while (stack != NULL)
	{
		if (stack->flag_0_3 < 4)
		{
			(*stack).cost = (*stack).index;
			if ((*stack).index <= median)
			{
				(*stack).cost = (*stack).cost;
			}
			else if ((*stack).index > median)
			{
				(*stack).cost = len_a - (*stack).cost;
			}
		}
		stack = (*stack).next;
	}
}

void	set_total_price(t_node_stack **b)
{
	size_t			total_price;
	t_node_stack	*actual;

	actual = *b;
	while (actual != NULL)
	{
		total_price = actual->cost + actual->target->cost;
		actual->cost = total_price;
		actual = actual->next;
	}
}

void	mark_as_cheapest(t_node_stack *cheapest_node)
{
	if (cheapest_node)
	{
		cheapest_node->cheapest = true;
	}
}

void	process_execution(t_node_stack **a, t_node_stack **b,
							t_node_stack *cheapest, size_t *stack_length)
{
	size_t	median;

	median = *stack_length / 2;
	rotate_operation_ci(a, cheapest, median);
	push_operation_ci(cheapest, a, b, stack_length);
	print_chunks(*a);
}

void	set_cheapest(t_node_stack *stack, size_t total_len, size_t flag)
{
	t_node_stack	*cheapest_node;

	if (!stack)
		return ;
	flag = check_flag(stack, &flag);
	cheapest_node = find_cheapest_node(stack, flag, total_len);
	mark_as_cheapest(cheapest_node);
}
