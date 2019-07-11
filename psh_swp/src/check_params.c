/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:14:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 16:15:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** check_sorted_params: check if the stack is already sorted. Returns -1 if it
** is sorted, and 0 if it's not.
*/

int					check_followed_params(t_stack *stack)
{
	int		i;
	int		j;

	if (stack->size < 1)
		return (-1);
	i = 0;
	while (i < stack->size - 1)
	{
		j = stack->array[i + 1];
		if (stack->array[i] == j - 1)
			i++;
		else
			return (i);
	}
	return (-1);
}

/*
** check_sorted_params: check if the stack is already sorted. Returns -1 if it
** is sorted, and 0 if it's not.
*/

int					check_sorted_params(t_stack *stack)
{
	int		i;

	if (stack->size < 1)
		return (-1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] < stack->array[i + 1])
			i++;
		else
			return (i);
	}
	return (-1);
}
