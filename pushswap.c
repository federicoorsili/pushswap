/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/20 13:53:44 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			indexing(t_stack *stack, int j)
{
	char	*used;
	int		*out;
	int 	i;
	int		k;
	int		min;

	i = 0;
	used = ft_calloc(500, sizeof(int));
	while (i < stack->len)
	{
		min = MAX_INT;
		k = -1;
		while (++k < stack->len)
			if (used[k] == 0 && stack->stack[k] <= min)
				min = stack->stack[k];
		k = -1;
		while (++k < stack->len)
		{
			if (stack->stack[k] == min && used[k] == 0)
			{
				used[k] = 1;
				stack->indexed[k] = j;
				j++;
			}
		}
		i++;
	}
	free(used);
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
	indexing(&stack, 1);
	return (stack);
}

int			main(int argc, char **argv, char **env)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*m;

	if (argc < 2)
		return (0);
	e = &env;
	m = malloc(300);
	stack_a = parse(argc, argv, stack_a);
	stack_b = init_stack(stack_b, stack_a.len);
	stack_a.indexed = ft_calloc(stack_a.len, sizeof(int));
	indexing(&stack_a , 1);
	//moves = define_moves();
	ft_print_arrint(stack_a.stack, stack_a.len, FRED);
	ft_print_arrint(stack_a.indexed, stack_a.len, FPURPLE);
	ft_print_arrint(stack_b.stack, stack_b.len, FGREEN);
	ft_print_arrint(stack_b.indexed, stack_b.len, FYELLOW);
	algorithm(&stack_a, &stack_b);
	while (1)
	{
		scanf("%s", m);
		move(&stack_a, &stack_b, m);
		print_stack(&stack_a, &stack_b);
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