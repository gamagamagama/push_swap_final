/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:42:27 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 08:53:33 by matus            ###   ########.fr       */
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

void	final_sort(t_node_stack **stack)
{
	size_t len;
	size_t median;
	t_node_stack *current;
	
	initialize_sort(stack, &len, &median, &current);
	process_stack(stack, median);
}

bool	sorted_stack(t_node_stack *stack)
{
	if (!stack)
		return(1);
	while (stack->next)
	{
		if (stack->tar_index > stack->next->tar_index)
		{
			return(false);
		}
		stack = stack->next;
	}
	return(true);
}

void	initialize_sort(t_node_stack **stack, size_t *len, size_t *median, t_node_stack **current)
{
	*len = stack_len(*stack);
	*median = *len / 2;
	*current = *stack;
	actindex(*stack);
}

void	initialize_sorter(t_node_stack **a, size_t *stack_length, t_node_stack **actual, t_node_stack **biggest)
{
	*biggest = find_biggest(*a);
	(*biggest)->flag_0_3 = 0;
	*actual = *a;
	*stack_length = stack_len(*a);
}

void	prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	size_t median;
	size_t temp_len;

	temp_len = stack_len(*b);
	reset_stack(*b);
	actindex(*b);
	median = temp_len / 2;
	set_price(*b);
	median_flag(*b, median);
	set_target_node_b_test(*a, *b, total_len);
}

void	prepare_stack_a(t_node_stack **a)
{
	size_t len_of_a;
	size_t median;

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
		return(actual->ci);
	}
	else if (flag == 2)
	{
		return(actual->co);
	}
	else if (flag == 3)
	{
		return(actual->cx);
	}
	return(0);
}

void	sort_c_iox(t_node_stack **a, t_node_stack **b, size_t *stack_length, size_t flag)
{
	size_t tmp_len;
	t_node_stack *actual;
	t_node_stack *biggest;
	int c_iox;

	c_iox = choose_wise(*a, flag);
	
	initialize_sorter(a, stack_length, &actual, &biggest);
	tmp_len = *stack_length;
  
	while ( c_iox != 0 && tmp_len > 3)
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
	t_node_stack *target;
	t_node_stack *cheapest;
	size_t flag;
	

	flag = 3;
	while ((*b) != NULL)
	{
		check_5con(a, b, total_len);
		psafch(a, b, total_len, flag);
		cheapest = retrun_cheapest(*b);
		if (cheapest == NULL)
			return;
		target = cheapest->target;
		perform_operations(a, b, cheapest, target);
		if(target->index == 0 && cheapest->index == 0)
		{
			pa(b, a);
		}
		flag = check_flag(*b, &flag);
	}
}

int	first_sort(t_node_stack **a, t_node_stack **b)
{
	size_t slen_a;
	size_t tmp_slen_a;
  
	slen_a = stack_len(*a);
	tmp_slen_a = slen_a;    
	print_chunks(*a);
	sort_c_iox(a, b, &tmp_slen_a, 1);
	sort_c_iox(a, b, &tmp_slen_a, 2);
	sort_c_iox(a, b, &tmp_slen_a, 3);
	three(a);
	return(0);
}
