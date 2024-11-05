/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_helps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:40:33 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 07:47:03 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mttp(t_node_stack **stack, t_node_stack *current, size_t median)
{
	while (current->index != current->tar_index)
	{
		if (current->index > median)
		{
			rra(stack);
		}
		else
		{
			ra(stack);
		}
		actindex(*stack);
	}
}

void	case_1_op(t_node_stack **b, t_node_stack *cheapest)
{
	if (cheapest->abov_median)
	{
		rb(b);
	}
	else
	{
		rrb(b);
	}
}

void	case_2_op(t_node_stack **a, t_node_stack *target)
{
	if (target->abov_median)
	{
		ra(a);
	}
	else
	{
		rra(a);
	}
}

void	case_3_op(t_node_stack **a, t_node_stack **b,
					t_node_stack *cheapest, t_node_stack *target)
{
	if (cheapest->abov_median && target->abov_median)
	{
		rr(a, b);
	}
	else if (!cheapest->abov_median && !target->abov_median)
	{
		rrr(a, b);
	}
	else if ((!cheapest->abov_median) && target->abov_median)
	{
		rrb(b);
		ra(a);
	}
	else
	{
		rra(a);
		rb(b);
	}
}

void	perform_operations(t_node_stack **a, t_node_stack **b,
							t_node_stack *cheapest, t_node_stack *target)
{
	while (cheapest->index != 0 || target->index != 0)
	{
		if (cheapest->index != 0 && target->index == 0)
		{
			case_1_op(b, cheapest);
		}
		else if (cheapest->index == 0 && target->index != 0)
		{
			case_2_op(a, target);
		}
		else if (cheapest->index != 0 && target->index != 0)
		{
			case_3_op(a, b, cheapest, target);
		}
		actindex(*a);
		actindex(*b);
	}
}
