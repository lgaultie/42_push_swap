/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:25:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/20 16:52:12 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		index_next_push(int median, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size && stack->array[i] >= median)
		i++;
	if (i == stack->size)
		return (-1);
	return (i);
}

void	divide_stack_a(int index_med, t_stack *stack_a, t_stack *stack_b)
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
			ft_putstr("pb\n");
			sort_b(stack_b);
		}
		else if (index_push <= stack_a->size / 2)
		{
			rotate(stack_a);
			ft_putstr("ra\n");
		}
		else if (index_push > stack_a->size / 2)
		{
			reverse_rotate(stack_a);
			ft_putstr("rra\n");
		}
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;

	while (check_sorted_params(stack_a) != -1)
	{
		index_med = find_median(stack_a);
		divide_stack_a(index_med, stack_a, stack_b);
		if (stack_a->size == 3)
			sort_three_last_numbers_on_a(stack_a);
	}
	while (stack_b->size > 0)
		calculate_max_value(stack_b, stack_a);
}
