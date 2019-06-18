/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:48:46 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/18 18:37:20 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	put_high_on_a(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	int		med;
	int		i;

	i = 0;
	index_med = find_median(stack_b);
	med = stack_b->array[index_med];
	while (i < stack_b->size)
	{
		if (stack_b->array[0] >= med)
		{
			push(stack_b, stack_a);
			ft_putstr("pa\n");
			i--;
		}
		else
		{
			rotate(stack_b);
			ft_putstr("rb\n");
		}
		i++;
	}
}
void	divide_a(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	int		med;
	int		i;

	i = 0;
	index_med = find_median(stack_a);
	med = stack_a->array[index_med];
	while (i < stack_a->size)
	{
		if (stack_a->array[0] <= med)
		{
			push(stack_a, stack_b);
			ft_putstr("pb\n");
			i--;
		}
		else
		{
			rotate(stack_a);
			ft_putstr("ra\n");
		}
		i++;
	}
}

int		find_max(t_stack *stack)
{
	int		i;
	int		max;

	i = 0;
	max = stack->array[0];
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}

/*
** select_b_to_a: on rotate jusqu'a trouver le plus grand qu'on a repéré avant
** on push sur a. on recommence. opti a faire: en push plsuieurs et trier
** a et b en meme temps.
*/

void	select_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		max;
	int		divided_size;

	i = 0;
	divided_size = stack_b->size / 2;
	while (stack_b->size > divided_size)
	{
		// printf("i = %d    max = %d\n", i, max);
		max = find_max(stack_b);
		if (stack_b->array[0] == max)
		{
			push(stack_b, stack_a);
			ft_putstr("pa\n");
		}
		else
		{
			rotate(stack_b);
			ft_putstr("rb\n");
		}
		i++;
	}
}

int		find_min(t_stack *stack)
{
	int		i;
	int		min;

	i = 0;
	min = stack->array[0];
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

void	sort_on_min(t_stack *stack_a, t_stack *stack_b)
{
	int		min;

	while (check_sorted_params(stack_a) != -1)
	{
		min = find_min(stack_a);
		// printf("array = %d   min = %d\n", stack_b)
		if (stack_a->array[0] == min)
		{
			push(stack_a, stack_b);
			ft_putstr("pb\n");
		}
		else
		{
			rotate(stack_a);
			ft_putstr("ra\n");
		}
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	int		med;

	//
	index_med = find_median(stack_a);
	med = stack_a->array[index_med];

	while (stack_a->size > 0)
		divide_a(stack_a, stack_b);
	select_b_to_a(stack_a, stack_b);
	while (stack_b->size > 0)
		put_high_on_a(stack_a, stack_b);
	sort_on_min(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		push(stack_b, stack_a);
		ft_putstr("pa\n");
	}
	//
	///////////////////////////////////////////
	ft_putstr("stack_a---------\n");
	print_tab(stack_a);
	ft_putstr("stack_b---------\n");
	print_tab(stack_b);
	printf("med = %d\n", med);
}
