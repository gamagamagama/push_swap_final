/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:42:27 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:54:40 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_stack	*find_target_node(t_node_stack *a,
								t_node_stack *b, size_t stack_length)
{
	t_node_stack	*current_a;
	t_node_stack	*target_node;
	size_t			best_index;

	target_node = NULL;
	best_index = stack_length;
	current_a = a;
	while (current_a)
	{
		if (current_a->tar_index > b->tar_index
			&& current_a->tar_index < best_index)
		{
			best_index = current_a->tar_index;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	return (target_node);
}

void	update_node_tar_index(t_node_stack *b, t_node_stack *target_node)
{
	if (target_node != NULL)
	{
		b->node_tar_index = target_node->tar_index;
		b->target = target_node;
	}
}

t_node_stack	*set_target_node_b_test(t_node_stack *a,
										t_node_stack *b, size_t stack_length)
{
	t_node_stack	*target_node;

	target_node = NULL;
	while (b != NULL)
	{
		target_node = find_target_node(a, b, stack_length);
		update_node_tar_index(b, target_node);
		b = b->next;
	}
	return (target_node);
}

void	three(t_node_stack **a)
{
	t_node_stack	*bigboy;

	bigboy = find_biggest(*a);
	if (bigboy == *a)
		ra(a);
	else if (bigboy == (**a).next)
		rra(a);
	if ((**a).tar_index > (*(**a).next).tar_index)
		sa(a);
}

void	others(t_node_stack **a, t_node_stack **b)
{
	int		tracker;
	size_t	total_len;

	total_len = stack_len(*a);
	if (*b == NULL)
	{
		defaults(*a);
		tracker = first_sort(a, b);
		if (tracker == 0)
		{
			sort_blok(a, b, total_len);
		}
		if (!sorted_stack(*a))
		{
			final_sort(a);
		}
		ft_stack_free(b);
	}
}
