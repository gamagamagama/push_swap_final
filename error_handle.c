/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:37:13 by matus             #+#    #+#             */
/*   Updated: 2024/10/29 18:33:14 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_node_stack **a)
{
	ft_stack_free(a);
	ft_putstr("Error\n");
	exit(1);
}

int	ft_dup_err(t_node_stack *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a -> value == num)
			return (1);
		a = a -> next;
	}
	return (0);
}

void	ft_stack_free(t_node_stack **stack)
{
	t_node_stack	*nxt_tmp;
	t_node_stack	*actual;

	if (!stack || !*stack)
		return ;
	actual = *stack;
	while (actual)
	{
		nxt_tmp = actual->next;
		free(actual);
		actual = nxt_tmp;
	}
	*stack = NULL;
}

int	ft_syntax_err(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	++str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}
