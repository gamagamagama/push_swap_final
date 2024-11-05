/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:45:58 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:24:34 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_index(t_node_stack **a)
{
	size_t			min_index;
	size_t			max_index;
	t_node_stack	*biggest;
	int				currentmax;

	initialize_target_indices(*a, &min_index, &max_index);
	biggest = find_biggest(*a);
	if (biggest)
	{
		currentmax = biggest->value;
		assign_target_indices(*a, &max_index, currentmax);
	}
}

void	initialize_target_indices(t_node_stack *a,
								size_t *min_index, size_t *max_index)
{
	t_node_stack	*smallest;
	t_node_stack	*biggest;

	biggest = find_biggest(a);
	smallest = find_lowest(a);
	*min_index = 0;
	*max_index = stack_len(a) - 1;

	if (smallest)
		smallest->tar_index = *min_index;
	if (biggest)
		biggest->tar_index = *max_index;
}

void	assign_target_indices(t_node_stack *a,
								size_t *max_index, int currentmax)
{
	t_node_stack	*nextbiggest;

	nextbiggest = find_next_bigboy(a, currentmax);
	while (nextbiggest)
	{
		if (nextbiggest->tar_index == 0)
		{
			currentmax = nextbiggest->value;
			nextbiggest->tar_index = --(*max_index);
			nextbiggest = find_next_bigboy(a, currentmax);
		}
		else
			a = a->next;
	}
}

void	assign_flag_to_node(t_node_stack *node, size_t min,
							size_t mid, size_t max)
{
	if (node->tar_index >= max)
	{
		node->flag_0_3 = 3;
		node->max = true;
	}
	else if (node->tar_index >= mid && node->tar_index < max)
	{
		node->flag_0_3 = 2;
		node->mid = true;
	}
	else if (node->tar_index >= min && node->tar_index < mid)
	{
		node->flag_0_3 = 1;
		node->min = true;
	}
	else
	{
		node->flag_0_3 = 0;
		node->def = true;
	}
}

void	flag_stack_nodes(t_node_stack *stack, size_t min,
						size_t mid, size_t max)
{
	while (stack != NULL)
	{
		assign_flag_to_node(stack, min, mid, max);
		stack = stack->next;
	}
}

void	flag_stack(t_node_stack *stack, size_t stacklen)
{
	size_t min; 
	size_t mid; 
	size_t max;
	
	calculate_chunks(stacklen, &min, &mid, &max);
	flag_stack_nodes(stack, min, mid, max);
}

