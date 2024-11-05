/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:10:29 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 07:17:40 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_stack	*find_biggest(t_node_stack *stack)
{
	long			num;
	t_node_stack	*bigboy;

	num = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (num < (*stack).value)
		{
			num = (*stack).value;
			bigboy = stack;
		}
		stack = (*stack).next;
	}
	return (bigboy);
}

t_node_stack	*find_lowest(t_node_stack *stack)
{
	long			num;
	t_node_stack	*smallboy;

	num = LONG_MAX;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (num > (*stack).value)
		{
			num = (*stack).value;
			smallboy = stack;
		}
		stack = (*stack).next;
	}
	return (smallboy);
}

t_node_stack	*find_next_bigboy(t_node_stack *stack, int currentMax)
{
	t_node_stack	*next_bigboy;

	next_bigboy = NULL;
	while (stack)
	{
		if (stack->value < currentMax && (next_bigboy == NULL
				|| stack->value > next_bigboy->value))
		{
			next_bigboy = stack;
		}
		stack = stack->next;
	}
	return (next_bigboy);
}
