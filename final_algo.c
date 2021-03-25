/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:57:57 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/25 15:20:59 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		index_min(t_stack *s)
{
	int min;
	int index;
	int i;

	i = 0;
	min = MAX_INT;
	index = 0;
	while (i < s->len)
	{
		if (s->stack[i] <= min)
		{
			min = s->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		index_max(t_stack *s)
{
	int max;
	int index;
	int i;

	i = 0;
	max = MIN_INT;
	index = 0;
	while (i < s->len)
	{
		if (s->stack[i] >= max)
		{
			max = s->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	final_algo(t_stack *s_a, t_stack *s_b)
{
	t_calcolo	calc;

	while (is_ordinated(s_a) == 0 || s_b->len != 0)
	{
		calcolo_dist(s_a, s_b, &calc);
		loop_01(s_a, s_b, &calc);
		loop_02(s_a, s_b, &calc);
		loop_03(s_a, s_b, &calc);
		loop_04(s_a, s_b, &calc);
		loop_05(s_a, s_b, &calc);
		loop_06(s_a, s_b, &calc);
		loop_07(s_a, s_b, &calc);
		if (calc.strategy == 999)
			break ;
	}
	while (is_ordinated(s_a) == 0 || s_b->len != 0)
	{
		if (index_min(s_a) < (s_a->len / 2))
			move(s_a, s_b, "ra");
		else
			move(s_a, s_b, "rra");
	}
}
