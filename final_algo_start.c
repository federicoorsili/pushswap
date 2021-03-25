/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:43:11 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/25 14:27:59 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	calc_init(t_stack *s_b, t_calcolo *calc)
{
	calc->min = MAX_INT;
	if (!(calc->arr_dist = ft_calloc(s_b->len + 1, sizeof(int))))
		exit(0);
	if (!(calc->arr_strategy = ft_calloc(s_b->len + 1, sizeof(int))))
		exit(0);
	calc->i_a = 0;
	calc->i_b = 0;
	calc->strategy = 999;
	calc->i = 0;
}

void	calcolo_dist_bis(t_stack *s_a, t_calcolo *calc)
{
	if (calc->not_find)
	{
		calc->j = index_max(s_a);
		calc->dir_a = calc_dir(s_a, s_a->stack[calc->j]);
		calc->dist_a = calc_dist(s_a, s_a->stack[calc->j]);
		calc->j++;
		calc->arr_dist[calc->i] = calc->dist_a + calc->dist_b + 1;
		calc->arr_strategy[calc->i] = 100 +
			(calc->dir_a * 10) + calc->dir_b;
	}
	if (calc->arr_dist[calc->i] < calc->min)
	{
		calc->strategy = calc->arr_strategy[calc->i];
		calc->i_a = calc->j;
		calc->i_b = calc->i;
		calc->min = calc->arr_dist[calc->i];
	}
	calc->i++;
}

int		is_error(t_stack *s)
{
	int i;

	i = 0;
	while (i < s->len - 1)
	{
		if (s->indexed[i] > s->indexed[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	final_algo_helper(t_stack *stack_a, t_stack *stack_b, t_lis *res_lis)
{
	int i;

	i = 0;
	stack_a->tot_move = 0;
	while (i < res_lis->len && is_error(stack_a))
	{
		if (res_lis->arr[i] == 0 && stack_a->len > 1)
			move(stack_a, stack_b, "pb");
		else if (stack_b->len > 1 && stack_b->stack[0] < stack_b->stack[1])
			move(stack_a, stack_b, "rr");
		else
			move(stack_a, stack_b, "ra");
		i++;
	}
}

void	final_algo_start(t_stack *stack_a, t_stack *stack_b)
{
	t_lis	res_lis;

	if (is_ordinated(stack_a))
		return ;
	if (esplora(stack_a, stack_b))
		stack_a->fagiolino = 1;
	if (!(res_lis.arr = ft_calloc(stack_a->len + 1, sizeof(int))))
		exit(0);
	ft_init_array_num(res_lis.arr, stack_a->len, 1);
	res_lis.len = stack_a->len;
	lis(&res_lis, stack_a);
	lis_select(&res_lis);
	final_algo_helper(stack_a, stack_b, &res_lis);
	free(res_lis.arr);
	final_algo(stack_a, stack_b);
}
