/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:45:49 by forsili           #+#    #+#             */
/*   Updated: 2021/03/20 00:48:00 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int max;

	i = 0;
	if (stack_b->len > stack_a->len)
		max = stack_b->len;
	else
		max = stack_a->len;
	while (i < max)
	{
		if (i < stack_a->len)
			printf(FRED"%.3d|%10.d   ", stack_a->indexed[i], 0);
		else
			printf(FRED"%3.d|%10.d   ", 0, 0);
		if (i < stack_b->len)
			printf(FGREEN"|%10.d|%.3d", 0, stack_b->indexed[i]);
		else
			printf(FGREEN"%10.d|   ", 0);
		printf("\n");
		i++;
	}
	printf("___________________________________________\n");
}

int			is_ordinated(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->indexed[i] != (i + 1))
			return (0);
		i++;
	}
	return (1);
}

int			src_min(t_stack *stack, int min)
{
	int i;

	while (i < stack->len)
	{
		if (stack->indexed[i] == min)
		{
			if (i < (stack->len / 2))
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

void		algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int min;
	int	src;
	int max;

	i = 0;
	min = 1;
	max = stack_a->len;
	printf("sss\n");
	while (1)
	{
		if (stack_a->indexed[0] == min)
		{
			move(stack_a, stack_b, "ra");
			min++;
		}
		else if (is_ordinated(stack_a))
		{
			if (stack_b->len == 0)
				break ;
			src = src_min(stack_b, min);
			while (stack_b->len != 0)
			{
				if (src == 0 && is_ordinated(stack_a))
				{
					min++;
					src = src_min(stack_b, min);
				}
				if (src > 0)
				{
					if (stack_b->indexed[0] == min)
					{
						move(stack_a, stack_b, "pa");
						move(stack_a, stack_b, "ra");
						min++;
						src = src_min(stack_b, min);
					}
					if (stack_b->indexed[0] == max)
					{
						move(stack_a, stack_b, "pa");
						max--;
					}
					else
						move(stack_a, stack_b, "rb");
				}
				if (src < 0)
				{
					if (stack_b->indexed[stack_b->len - 1] == min)
					{
						move(stack_a, stack_b, "rrb");
						move(stack_a, stack_b, "pa");
						move(stack_a, stack_b, "ra");
						min++;
						src = src_min(stack_b, min);
					}
					if (stack_b->indexed[stack_b->len - 1] == max)
					{
						move(stack_a, stack_b, "pa");
						max--;
					}
					else
						move(stack_a, stack_b, "rrb");
				}
				
				i++;	
			}
		}
		else
			move(stack_a, stack_b, "pb");
		//print_stack(stack_a, stack_b);
		i++;
	}
	printf(FYELLOW"\n");
	ft_print_arrint(stack_a->stack, stack_a->len, "--");
	printf(FYELLOW"RESULT: %d %d %d\n", i, stack_a->len, stack_b->len);
}