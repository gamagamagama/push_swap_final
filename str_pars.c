/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:45:47 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:20:26 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_counter(char *str, char c)
{
	size_t	counter;
	bool	in_word;

	counter = 0;
	if (!str)
		return (0);
	while (*str)
	{
		in_word = false;
		while (*str == c)
			str++;
		while (*str && *str != c)
		{
			if (!in_word)
			{
				counter++;
				in_word = true;
			}
			str++;
		}
	}
	return (counter);
}

static char	*get_word(char *str, char c, bool yes)
{
	static size_t	position = 0;
	char			*next;
	size_t			len;
	size_t			i;

	len = 0;
	i = 0;
	if (yes)
	{
		while (str[position] == c)
			position++;
		while (str[position + len] != c && str[position + len])
			len++;
		next = malloc(len * sizeof(char) + 1);
		if (!next)
			return (NULL);
		while (str[position] != c && str[position])
			next[i++] = str[position++];
		next[i] = '\0';
		return (next);
	}
	return (NULL);
}


char	**ft_spliter(char *str, char c)
{
	size_t	index;
	int		word_count;
	char	**new_array;

	word_count = word_counter(str, c);
	index = 0;
	if (word_count == 0)
		exit(1);
	new_array = malloc(sizeof (char *) * (size_t)(word_count + 2));
	if (!new_array)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (str[index] == 0)
		{
			new_array[index] = malloc(sizeof(char));
			if (new_array[index] == NULL)
				return (NULL);
			new_array[index++][0] = '\0';
			continue ;
		}
		new_array[index++] = get_word(str, c, ft_printable(str));
	}
	new_array[index] = NULL;
	return (new_array);
}

bool	ft_printable(char *str)
{
	bool	yes;

	yes = false;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			yes = true;
		}
		str++;
	}
	return (yes);
}
