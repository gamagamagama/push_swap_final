/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:25:12 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:27:36 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_stack(t_node_stack *stack, size_t stacklen)
{
	size_t	min;
	size_t	mid;
	size_t	max;

	calculate_chunks(stacklen, &min, &mid, &max);
	flag_stack_nodes(stack, min, mid, max);
}
