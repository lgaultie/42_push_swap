/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:01:39 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/10 17:14:07 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	index_next_push(int median, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size && stack->array[i] >= median)
		i++;
	if (i == stack->size)
		return (-1);
	return (i);
}

static void	divide_stack_b2(int index_push, t_stack *stack_b)
{
	if (index_push <= stack_b->size / 2)
	{
		rotate(stack_b);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rb\n", 1)))
			return ;
	}
	else if (index_push > stack_b->size / 2)
	{
		reverse_rotate(stack_b);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rrb\n", 1)))
			return ;
	}
}

int		divide_stack_b(int index_med, t_stack *stack_a, t_stack *stack_b, int nb_push)
{
	int		median;
	int		index_push;

	median = stack_b->array[index_med];
	index_push = 0;
	while (index_push != -1)
	{
		index_push = index_next_push(median, stack_b);
		if (index_push == 0)
		{
			push(stack_b, stack_a);
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "pa\n", 1)))
				return (-1);
			nb_push++;
		}
		else
			divide_stack_b2(index_push, stack_b);
	}
	return (nb_push);
}
