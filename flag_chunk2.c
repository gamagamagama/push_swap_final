/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_chunk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:37:58 by matus             #+#    #+#             */
/*   Updated: 2024/10/29 18:38:10 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_chunks(t_node_stack *stack, int *cx, int *co, int *ci)
{
	t_node_stack	*current;

	*cx = 0;
	*co = 0;
	*ci = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->min == true)
		{
			(*ci)++;
		}
		else if (current->mid == true)
		{
			(*co)++;
		}
		else if (current->max == true)
		{
			(*cx)++;
		}
		current = current->next;
	}
}
