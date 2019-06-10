/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:53:51 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/10 18:20:33 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		index_of_smallest(t_stack *stack)
{
	int		i;
	int		min;
	int		index;

	i = 0;
	min = stack->array[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
		{
			min = stack->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

/*
** selection_sort: met le plus petit element en haut de la pile a avec des
** rotate et reverse_rotate, puis push le sur b. Repeat... Puis repush la pile
** b sur a --> trié
*/

void 	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min;

	// printf("min: stack->array[%d] = %d\n", i, stack_a->array[i]);
	while (stack_a->size > 0)
	{
		i = index_of_smallest(stack_a);
		min = stack_a->array[i];
		// printf("i = %d   min = %d\n", i, min);
		// printf("size = %d    stack->array[0] = %d     min = stack_a->array[%d] = %d\n",stack_a->size, stack_a->array[0], i, stack_a->array[i]);
		if (stack_a->array[0] > min)
		{
			if (i > stack_a->size / 2)
			{
				reverse_rotate(stack_a);
				ft_putstr("rra\n");
			}
			if (i <= stack_a->size / 2)
			{
				rotate(stack_a);
				ft_putstr("ra\n");
			}
			// print_tab(stack_a);
			// ft_putchar('\n');
		}
		if (stack_a->array[0] == min)
		{
			push(stack_a, stack_b);
			ft_putstr("pb\n");
			// print_tab(stack_a);
			// ft_putchar('\n');
		}
	}
	while (stack_b->size > 0)
	{
		push(stack_b, stack_a);
		ft_putstr("pa\n");
	}
}
