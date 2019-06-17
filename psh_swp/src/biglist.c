/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:53 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 17:39:33 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	little_sort_b(t_stack *stack_b, t_stack *stack_a)
{
	ft_putstr("-stack_a-----------\n");
	print_tab(stack_a);
	ft_putstr("-stack_b-----------\n");
	print_tab(stack_b);
}

void	divide_stack_a(int index_med, t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		index_push;
	int		i;

	i = 0;
	(void)stack_b;
	median = stack_a->array[index_med];
	index_push = 0;
	while (index_push != -1)
	{
		index_push = index_next_push(median, stack_a);
		// printf("index_push = %d\n", index_push);
		if (index_push == 0)
		{
			push(stack_a, stack_b);
			ft_putstr("pb\n");
			// little_sort_b(stack_b, stack_a);
			// ici on pourrait trier b en meme temps que a?
		}
		else
		{
			if (index_push <= stack_a->size / 2)
			{
				rotate(stack_a);
				ft_putstr("ra\n");
			}
			if (index_push > stack_a->size / 2)
			{
				reverse_rotate(stack_a);
				ft_putstr("rra\n");
			}
		}
	}
}


void	put_max_on_top(t_stack *stack_b, t_stack *stack_a)
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
	// printf("stack->array[%d] = %d\n", index_max, stack_b->array[index_max]);
	// printf("index_max = %d  stack_b->size / 2 = %d \n", index_max,  stack_b->size / 2);
	if (stack_b->array[1] == max)
	{
		swap(stack_b);
		ft_putstr("sb\n");
	}
	else if (index_max <= stack_b->size / 2)
	{
		while (stack_b->array[0] != max)
		{
			rotate(stack_b);
			ft_putstr("rb\n");
		}
	}
	else if (index_max > stack_b->size / 2)
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
		put_max_on_top(stack_b, stack_a);

	// printf("med_small_a = %d    med_small_b = %d\n", stack_a->array[med_small_a], stack_b->array[med_small_b]);
	// ft_putstr("stack_a ---------\n");
	// print_tab(stack_a);
	// ft_putstr("stack_b ---------\n");
	// print_tab(stack_b);
}

// void	divide_stack_a(int index_med, t_stack *stack_a, t_stack *stack_b)
// {
// 	int		median;
// 	int		i;
//
// 	i = 0;
// 	median = stack_a->array[index_med];
// 	while (i < stack_a->size - 1)
// 	{
// 		if (stack_a->array[0] < median)
// 		{
// 			push(stack_a, stack_b);
// 			ft_putstr("pb\n");
// 			i--;
// 		}
// 		else
// 		{
// 			// printf("i = %d      size = %d      array[i] = %d     median = %d\n", i, stack_a->size, stack_a->array[i], median);
// 			rotate(stack_a);
// 			ft_putstr("ra\n");
// 		}
// 		i++;
// 	}
// }
