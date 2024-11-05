/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:59:12 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:53:09 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stack_a(t_node_stack **a)
{
	size_t	len_of_a;
	size_t	median;

	len_of_a = stack_len(*a);
	median = len_of_a / 2;
	default_flag(*a);
	reset_stack(*a);
	actindex(*a);
	median_flag(*a, median);
	set_price(*a);
}

int	choose_wise(t_node_stack *actual, size_t flag)
{
	if (flag == 1)
	{
		return (actual->ci);
	}
	else if (flag == 2)
	{
		return (actual->co);
	}
	else if (flag == 3)
	{
		return (actual->cx);
	}
	return (0);
}

void	sort_c_iox(t_node_stack **a, t_node_stack **b,
					size_t *stack_length, size_t flag)
{
	size_t			tmp_len;
	t_node_stack	*actual;
	t_node_stack	*biggest;
	int				c_iox;

	c_iox = choose_wise(*a, flag);
	initialize_sorter(a, stack_length, &actual, &biggest);
	tmp_len = *stack_length;
	while (c_iox != 0 && tmp_len > 3)
	{
		actual = process_iteration(a, &tmp_len, flag);
		c_iox = choose_wise(*a, flag);
		if (!actual)
			return ;
		if (actual == biggest && flag >= 2)
		{
			handle_biggest(a, actual, biggest);
			actual = process_iteration(a, &tmp_len, flag);
		}
		process_execution(a, b, actual, &tmp_len);
		actual = *a;
		update_chunk_index(*a, &c_iox, flag);
		*stack_length = tmp_len;
	}
}

void	sort_blok(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	t_node_stack	*target;
	t_node_stack	*cheapest;
	size_t			flag;

	flag = 3;
	while ((*b) != NULL)
	{
		check_5con(a, b, total_len);
		psafch(a, b, total_len, flag);
		cheapest = retrun_cheapest(*b);
		if (cheapest == NULL)
			return ;
		target = cheapest->target;
		perform_operations(a, b, cheapest, target);
		if (target->index == 0 && cheapest->index == 0)
		{
			pa(b, a);
		}
		flag = check_flag(*b, &flag);
	}
}

int	first_sort(t_node_stack **a, t_node_stack **b)
{
	size_t	slen_a;
	size_t	tmp_slen_a;

	slen_a = stack_len(*a);
	tmp_slen_a = slen_a;
	print_chunks(*a);
	sort_c_iox(a, b, &tmp_slen_a, 1);
	sort_c_iox(a, b, &tmp_slen_a, 2);
	sort_c_iox(a, b, &tmp_slen_a, 3);
	three(a);
	return (0);
}
