/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:25:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 15:12:06 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_tab(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(stack->array[i]);
		ft_putchar('\n');
		i++;
	}
}

static int	index_next_push(int median, t_stack *stack_a)
{
	int		i;

	i = 0;
	while (i < stack_a->size && stack_a->array[i] >= median)
		i++;
	if (i == stack_a->size)
		return (-1);
	return (i);
}

/*
** divide_stack_a2: Seeks the next number to push on b: the next number lesser
** than the median. After pushing on b, calls sort_b to pre-sort the stack.
*/

static void	divide_stack_a2(int index_push, t_stack *stack_a, t_stack *stack_b)
{
	if (index_push <= stack_a->size / 2)
	{
		rotate(stack_a);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "ra\n", 1)))
			return ;
	}
	else if (index_push > stack_a->size / 2)
	{
		reverse_rotate(stack_a);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
			return ;
	}
}

/*
** divide_stack_a: Seeks the next number to push on b: the next number lesser
** than the median. After pushing on b, calls sort_b to pre-sort the stack.
*/

void		divide_stack_a(int index_med, t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		index_push;

	median = stack_a->array[index_med];
	index_push = 0;
	while (index_push != -1)
	{
		index_push = index_next_push(median, stack_a);
		if (index_push == 0)
		{
			push(stack_a, stack_b);
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "pb\n", 1)))
				return ;
			sort_b(stack_b);
		}
		else
			divide_stack_a2(index_push, stack_a, stack_b);
	}
}
