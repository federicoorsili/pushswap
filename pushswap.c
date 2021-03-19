/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/19 19:04:50 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			*indexing(int *arr, int len, int j)
{
	char	used[500];
	int		*out;
	int 	i;
	int		k;
	int		min;

	i = -1;
	out = malloc(len * sizeof(int));
	while (++i < len)
	{
		min = MAX_INT;
		k = -1;
		while (++k < len)
			if (!used[k])
				if (arr[k] <= min)
					min = arr[k];
		k = -1;
		while (++k < len)
			if (arr[k] == min)
			{
				used[k] = 1;
				out[k] = j;
				j++;
			}
	}
	return (out);
}

t_stack		parse(int argc, char **argv, t_stack stack)
{
	int		i;
	char	**tmp;
	int		*out;

	tmp = ft_split(argv[1], ' ');
	if (!(out = malloc(ft_matrix_len(tmp) * sizeof(int))))
		return (stack);
	i = 0;
	while (tmp[i])
	{
		out[i] = ft_atoi(tmp[i]);
		i++;
	}
	stack.len = i;
	ft_free_matrix(tmp, ft_matrix_len(tmp));
	stack.stack = out;
	return (stack);
}

t_stack		init_stack(t_stack stack, int len)
{
	if (!(stack.stack = ft_calloc(len, sizeof(int *))))
		return (stack);
	stack.len = 0;
	stack.indexed = indexing(stack.stack, stack.len, 1);
	return (stack);
}

int			main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		**moves;
	char		*m;

	stack_a = parse(argc, argv, stack_a);
	stack_b = init_stack(stack_b, stack_a.len);
	stack_a.indexed = indexing(stack_a.stack, stack_a.len, 1);
	moves = define_moves();
	ft_print_arrint(stack_a.stack, stack_a.len, FRED);
	ft_print_arrint(stack_a.indexed, stack_a.len, FPURPLE);
	ft_print_arrint(stack_b.stack, stack_b.len, FGREEN);
	ft_print_arrint(stack_b.indexed, stack_b.len, FYELLOW);
	while (1)
	{
		scanf("%s", m);
		move(&stack_a, &stack_b, m);
		ft_print_arrint(stack_a.stack, stack_a.len, FRED);
	ft_print_arrint(stack_a.indexed, stack_a.len, FPURPLE);
	ft_print_arrint(stack_b.stack, stack_b.len, FGREEN);
	ft_print_arrint(stack_b.indexed, stack_b.len, FYELLOW);
	printf("\n");
	}
	//do_sasb(&stack_a);
	//ft_print_arrint(stack_a.stack, stack_a.len, "-->");
	//ft_print_arrint(stack_a.indexed, stack_a.len, "ooo>");
	//do_ss(&stack_a, &stack_b);
	//ft_print_arrint(stack_a.stack, stack_a.len, "-->");
	//ft_print_arrint(stack_a.indexed, stack_a.len, "ooo>");
	//shift_rev_stack(&stack_a);
	//shift_stack(&stack_a, 0);
	//shift_stack(&stack_a, 0);
	//do_push(&stack_a, &stack_b);
	//do_push(&stack_a, &stack_b);
	//rotate_one_stack(&stack_a);
	//rotate_two_stack(&stack_a, &stack_b);
	//ft_print_arrint(stack_a.stack, stack_a.len, "aaa>");
	//ft_print_arrint(stack_a.indexed, stack_a.len, "AAA>");
	//ft_print_arrint(stack_b.stack, stack_b.len, "bbb>");
	//ft_print_arrint(stack_b.indexed, stack_b.len, "BBB>");
	return (0);
}