/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:15:13 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:38:17 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node_stack	*a;
	t_node_stack	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1 || (argc == 2 && !argv[1][0])))
		argv = ft_spliter(argv[1], ' ');
	stack_init(&a, argv + 1);
	target_index(&a);
	if (!((sorted_stack(a))))
	{
		if ((stack_len(a) == 2))
			sa(&a);
		else if ((stack_len(a) == 3))
			three(&a);
		else
			others(&a, &b);
	}
	ft_stack_free(&a);
	return (0);
}
