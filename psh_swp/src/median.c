/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:54:07 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 13:35:39 by lgaultie         ###   ########.fr       */
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

// int		find_median1(t_stack *stack)
// {
// 	int			*cpy;
// 	int			i;
// 	int			median;
// 	int			min;
//
// 	i = 0;
// 	cpy = malloc(sizeof(int) * stack->size);
// 	while (i < stack->size)
// 	{
// 		cpy[i] = stack->array[i];
// 		i++;
// 	}
// 	i = 1;
// 	while (i < stack->size)
// 	{
// 		if (cpy[i - 1] > cpy[i])
// 		{
// 			median = cpy[i - 1];
// 			cpy[i - 1] = cpy[i];
// 			cpy[i] = median;
// 			i = 0;
// 		}
// 		i++;
// 	}
// 	min = cpy[0];
// 	i = stack->size / 2;
// 	median = cpy[i];
// 	free(cpy);
// 	return (find_index_median(median, min, stack));
// }


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
