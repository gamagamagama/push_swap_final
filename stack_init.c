/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:42:35 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 09:46:31 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	in_node(t_node_stack *node)
{
	node->index = 0;
	node->tar_index = 0;
	node->node_tar_index = 0;
	node->cost = 0;
	node->flag_0_3 = 0;
	node->cx = 0;
	node->co = 0;
	node->ci = 0;
	node->max = false;
	node->mid = false;
	node->min = false;
	node->def = false;
	node->abov_median = false;
	node->cheapest = false;
}

static void	add_node(t_node_stack **stack, int num)
{
	t_node_stack	*new_node;
	t_node_stack	*last_node;

	if (!(stack))
		return ;
	new_node = malloc(sizeof(t_node_stack));
	if (!(new_node))
		return ;
	new_node ->next = NULL;
	new_node->value = num;
	in_node(new_node);
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57 && *str)
	{
		res = res * 10 + (*str++ - '0');
	}
	return (res * sign);
}

void	stack_init(t_node_stack **a, char **argv)
{
	long	num;
	size_t	i;

	i = 0;

	while (argv[i])
	{
		if (ft_syntax_err(argv[i]))
			handle_error(a);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			handle_error(a);
		if (ft_dup_err(*a, (int)num))
			handle_error(a);
		add_node(a, (int)num);
		i++;
	}
}

void	actindex(t_node_stack *stack)
{
	size_t	i;

	i = 0;
	if (stack == NULL)
	{
		return ;
	}
	while (stack != NULL)
	{
		((*stack).index) = i;
		stack = (*stack).next;
		i++;
	}
}
