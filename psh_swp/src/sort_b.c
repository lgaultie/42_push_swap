/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:27:32 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 16:19:19 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	put_max2(int max, int index_m, t_stack *stack_b, t_stack *stack_a)
{
	if (index_m > stack_b->size / 2 && stack_b->size > 1)
	{
		while (stack_b->array[0] != max)
		{
			reverse_rotate(stack_b);
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rrb\n", 1)))
				return ;
		}
	}
	if (stack_b->size > 0)
	{
		push(stack_b, stack_a);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "pa\n", 1)))
			return ;
	}
}

static void	put_max(int max, int index_m, t_stack *stack_b, t_stack *stack_a)
{
	if (index_m <= stack_b->size / 2 && stack_b->size > 1)
	{
		while (stack_b->array[0] != max)
		{
			rotate(stack_b);
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rb\n", 1)))
				return ;
		}
	}
	put_max2(max, index_m, stack_b, stack_a);
}

int			check_sorted_params_reverse(t_stack *stack)
{
	int		i;

	if (stack->size < 1)
		return (-1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			i++;
		else
			return (i);
	}
	return (-1);
}

/*
** sort_b: if the first number on stack_b is inferior than the median,
** put it in the end. So as to have less rotate to make after, when emptying
** stack_b with big numbers first.
*/

void		sort_b(t_stack *stack)
{
	int		index_median;
	int		median;

	index_median = find_median(stack);
	median = stack->array[index_median];
	if (check_sorted_params_reverse(stack) != -1)
	{
		if ((stack->array[0] < median && stack->size > 1) \
			|| (stack->array[0] < stack->array[1] && stack->size == 2))
		{
			rotate(stack);
			if (!(stack->buf = ft_strjoinfree(stack->buf, "rb\n", 1)))
				return ;
		}
	}
}

/*
** calculate_max_value: finds biggest int in list, put it on top of stack, push.
*/

void		calculate_max_value(t_stack *stack_b, t_stack *stack_a)
{
	int		i;
	int		max;
	int		index_max;

	i = 0;
	index_max = 0;
	max = stack_b->array[0];
	while (i < stack_b->size)
	{
		if (stack_b->array[i] > max)
		{
			max = stack_b->array[i];
			index_max = i;
		}
		i++;
	}
	put_max(max, index_max, stack_b, stack_a);
}
