/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:20:59 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 08:44:57 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_stack	*process_iteration(t_node_stack **a,
									size_t *stack_length, size_t flag)
{
	t_node_stack	*cheapest;

	actindex(*a);
	set_price(*a);
	set_cheapest(*a, *stack_length, flag);
	cheapest = retrun_cheapest(*a);
	return (cheapest);
}

void	handle_biggest(t_node_stack **a,
						t_node_stack *actual, t_node_stack *biggest)
{
	if (actual->tar_index == biggest->tar_index)
	{
		ra(a);
		actual = *a;
	}
}
