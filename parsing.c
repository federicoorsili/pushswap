/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:57:00 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 10:50:04 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				check_double(int *arr, int len)
{
	int i;
	int k;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (arr[i] == arr[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int				is_a_flag(char *str)
{
	if (!ft_strcmp(str, "-v") && ft_strlen(str) == 2)
		return (1);
	else if (!ft_strcmp(str, "-c") && ft_strlen(str) == 2)
		return (1);
	else if (!ft_strcmp(str, "-file") && ft_strlen(str) == 5)
		return (1);
	return (0);
}

int				count_for_alloc(int argc, char **argv)
{
	int		i;
	int		k;
	char	**split;

	i = 1;
	k = 0;
	split = NULL;
	while (i < argc && !is_a_flag(argv[i]))
	{
		split = ft_split(argv[i], ' ');
		k += ft_matrix_len(split);
		ft_free_matrix(split, ft_matrix_len(split));
		i++;
	}
	return (k + 1);
}

void			flag_taker_pushswap(t_stack *stack, int argc, char **argv)
{
	int		i;

	stack->error = 0;
	stack->file = 0;
	stack->visual = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-v") && ft_strlen(argv[i]) == 2)
			stack->visual = 1;
		i++;
	}
}

void			flag_taker(t_stack *stack, int argc, char **argv)
{
	int		i;

	stack->error = 0;
	stack->file = 0;
	stack->visual = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-v") && ft_strlen(argv[i]) == 2)
			stack->visual = 1;
		else if (!ft_strcmp(argv[i], "-file") && ft_strlen(argv[i]) == 5)
			stack->file = 1;
		i++;
	}
}
