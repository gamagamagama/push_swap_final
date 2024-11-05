/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:38:15 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:58:56 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max)
{
	size_t	len_of_chunk;
	int		remainder;

	len_of_chunk = stacklen / 3;
	remainder = stacklen % 3;
	*min = 0;
	*mid = *min + len_of_chunk;
	*max = *mid + len_of_chunk;
	if (remainder > 0)
	{
		(*max) += 1;
		remainder--;
	}
	if (remainder > 0)
	{
		(*mid) += 1;
	}
}

void	median_flag(t_node_stack *stack, size_t median)
{
	while (stack)
	{
		if (stack->index >= median)
		{
			stack->abov_median = false;
		}
		else
		{
			stack->abov_median = true;
		}
		stack = stack->next;
	}
}

void	default_flag(t_node_stack *stack)
{
	while (stack != NULL)
	{
		if ((*stack).flag_0_3 != 0 && (*stack).flag_0_3 <= 3)
		{
			(*stack).flag_0_3 = 0;
		}
		stack = stack->next;
	}
}

void	defaults(t_node_stack *stack)
{
	default_flag(stack);
	flag_stack(stack, stack_len(stack));
	actindex(stack);
	set_price(stack);
}

void	update_chunk_index(t_node_stack *a, int *c, size_t flag)
{
	if (flag == 1)
	{
		*c = a->ci;
	}
	else if (flag == 2)
	{
		*c = a->co;
	}
	else if (flag == 3)
	{
		*c = a->cx;
	}
}
