/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:27:32 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/20 16:46:19 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	put_max_on_top(int max, int index_m, t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->array[1] == max)
	{
		swap(stack_b);
		ft_putstr("sb\n");
	}
	else if (index_m <= stack_b->size / 2)
	{
		while (stack_b->array[0] != max)
		{
			rotate(stack_b);
			ft_putstr("rb\n");
		}
	}
	else if (index_m > stack_b->size / 2)
	{
		while (stack_b->array[0] != max)
		{
			reverse_rotate(stack_b);
			ft_putstr("rrb\n");
		}
	}
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	calculate_max_value(t_stack *stack_b, t_stack *stack_a)
{
	int		i;
	int		max;
	int		index_max;

	i = 0;
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
	put_max_on_top(max, index_max, stack_b, stack_a);
}

/*
** je calcule la mediane, si le chiffre en haut est > a la mediane, je rotate
** sinon je fais rien
*/

void	sort_b(t_stack *stack)
{
	int		index_median;
	int		median;

	index_median = find_median(stack);
	median = stack->array[index_median];
	if (stack->array[0] < median && stack->size > 1)
	{
		rotate(stack);
		ft_putstr("rb\n");

		// print_tab(stack);
		// ft_putstr("---------\n");
	}
}
