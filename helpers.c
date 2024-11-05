/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:38:31 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 11:02:00 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	set_median(t_node_stack *stack, size_t flag )
{
	size_t			sum;
	size_t			median;
	size_t			counter;
	t_node_stack	*current;

	current = stack;
	counter = 0;
	sum = 0;
	while (current != NULL)
	{
		if ((*current).flag_0_3 == flag)
		{
			sum = sum + (*current).tar_index;
			counter++;
		}
		current = current->next;
	}
	median = sum / counter;
	return (median);
}

size_t	stack_len(t_node_stack *stack)
{
	size_t	counter;

	counter = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

t_node_stack	*find_cheapest_node(t_node_stack *stack,
									size_t flag, size_t total_len)
{
	size_t			cheapest_index;
	t_node_stack	*cheapest_node;

	cheapest_index = total_len;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->flag_0_3 == flag)
		{
			if (is_cheaper(stack, &cheapest_index, cheapest_node))
			{
				cheapest_index = stack->cost;
				cheapest_node = stack;
			}
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

t_node_stack	*retrun_cheapest(t_node_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
		{
			return (stack);
		}
		stack = (*stack).next;
	}
	return (NULL);
}

t_node_stack	*find_last_node(t_node_stack *stack)
{
	if (!(stack))
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
