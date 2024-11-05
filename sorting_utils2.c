/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:54:24 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:52:59 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_node_stack **stack)
{
	size_t			len;
	size_t			median;
	t_node_stack	*current;

	initialize_sort(stack, &len, &median, &current);
	process_stack(stack, median);
}

bool	sorted_stack(t_node_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->tar_index > stack->next->tar_index)
		{
			return (false);
		}
		stack = stack->next;
	}
	return (true);
}

void	initialize_sort(t_node_stack **stack, size_t *len,
						size_t *median, t_node_stack **current)
{
	*len = stack_len(*stack);
	*median = *len / 2;
	*current = *stack;
	actindex(*stack);
}

void	initialize_sorter(t_node_stack **a, size_t *stack_length,
							t_node_stack **actual, t_node_stack **biggest)
{
	*biggest = find_biggest(*a);
	(*biggest)->flag_0_3 = 0;
	*actual = *a;
	*stack_length = stack_len(*a);
}

void	prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	size_t	median;
	size_t	temp_len;

	temp_len = stack_len(*b);
	reset_stack(*b);
	actindex(*b);
	median = temp_len / 2;
	set_price(*b);
	median_flag(*b, median);
	set_target_node_b_test(*a, *b, total_len);
}
