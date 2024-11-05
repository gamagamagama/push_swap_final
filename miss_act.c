/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miss_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:40:23 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:40:52 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_operation_ci(t_node_stack **a, t_node_stack *cheapest,
							size_t median)
{
	t_node_stack	*actual;

	actual = *a;
	while (!(*actual).cheapest)
	{
		if ((*cheapest).index < median)
		{
			while ((!(*actual).cheapest))
			{
				ra(a);
				actual = *a;
			}
		}
		else if ((*cheapest).index >= median)
		{
			while (!(*actual).cheapest)
			{
				rra(a);
				actual = *a;
			}
		}
		actual = *a;
	}
}

void	push_operation_ci(t_node_stack *cheapest_node, t_node_stack **a,
						t_node_stack **b, size_t *tmp_slen_a)
{
	t_node_stack	*stack;
	static size_t	chunk_median;
	static size_t	flag;

	stack = *a;
	if (!chunk_median || flag != stack->flag_0_3)
	{
		flag = (stack)->flag_0_3;
		chunk_median = set_median(stack, (stack)->flag_0_3);
	}
	if ((*stack).cheapest)
	{
		if ((*cheapest_node).tar_index >= chunk_median)
		{
			pb(a, b);
			(*tmp_slen_a)--;
		}
		else if ((*cheapest_node).tar_index < chunk_median)
		{
			pb(a, b);
			rb(b);
			(*tmp_slen_a)--;
		}
	}
}

size_t	check_flag(t_node_stack *stack, size_t *flag)
{
	t_node_stack	*current;

	while (*flag > 0)
	{
		current = stack;
		while (current)
		{
			if (current->flag_0_3 == *flag)
			{
				return (*flag);
			}
			current = current->next;
		}
		(*flag)--;
	}
	return (*flag);
}

void	ft_putstr(char *str)
{
	size_t	count;
	size_t	result;

	count = 0;
	if (str == NULL)
	{
		return ;
	}
	while (str[count])
		count++;
	result = write(1, str, count);
	if (result == 0)
	{
		ft_putstr("Error\n");
	}
	else if (result < count)
	{
		ft_putstr("Error\n");
	}
}

bool	is_cheaper(t_node_stack *current_node, size_t *cheapest_index,
					t_node_stack *cheapest_node)
{
	if (current_node->cost < *cheapest_index)
	{
		return (true);
	}
	else if (current_node->cost == *cheapest_index)
	{
		if (current_node->tar_index > cheapest_node->tar_index)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
	return (false);
}
