/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:54:07 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 18:55:20 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		find_index_median(int median, int min, t_stack *stack)
{
	int		i;

	i = 0;
	while (median >= min)
	{
		while (stack->array[i] != median && i < stack->size)
			i++;
		if (i < stack->size)
			return (i);
		else
		{
			median--;
			i = 0;
		}
	}
	return (0);
}

int		find_median(t_stack *stack)
{
	int		i;
	int		median;
	int		min;

	median = 0;
	i = 0;
	min = stack->array[0];
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		median = median + stack->array[i];
		i++;
	}
	median = median / i;
	return (find_index_median(median, min, stack));
}
