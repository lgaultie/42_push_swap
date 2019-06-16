/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:53 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/16 15:32:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <push_swap.h>
//
// int		find_median(t_stack *stack)
// {
// 	int		i;
// 	// int		index_median;
// 	int		median;
// 	int		min;
//
// 	median = 0;
// 	i = 0;
// 	min = stack->array[0];
// 	while (i < stack->size)
// 	{
// 		if (stack->array[i] < min)
// 			min = stack->array[i];
// 		median = median + stack->array[i];
// 		i++;
// 	}
// 	median = median / i;
// 	printf("median = %d    min = %d\n", median, min);
// 	i = 0;
// 	while (median >= min)
// 	{
// 		while (stack->array[i] != median && i < stack->size)
// 			i++;
// 		// printf("i = %d   size = %d\n", i,stack->size);
// 		if (i < stack->size)
// 			return (i);
// 		else
// 		{
// 			// printf("median = %d\n", median);
// 			median--;
// 			i = 0;
// 		}
// 	}
// 	return (0);
// }
//
// void	divide_stack_a(int index_med, t_stack *stack_a, t_stack *stack_b)
// {
// 	int		median;
// 	int		i;
//
// 	i = 0;
// 	median = stack_a->array[index_med];
// 	while (i < stack_a->size)
// 	{
// 		if (stack_a->array[0] < median)
// 		{
// 			push(stack_a, stack_b);
// 			ft_putstr("pb\n");
// 			i--;
// 		}
// 		else
// 		{
// 			rotate(stack_a);
// 			ft_putstr("ra\n");
// 		}
// 		i++;
// 	}
// }
//
// void	check_two_first(t_stack *stack_a, t_stack *stack_b)
// {
// 	int			i;
//
// 	i = 0;
// 	if (stack_a->array[i] < stack_a->array[i + 1] && stack_b->array[i] < stack_b->array[i + 1])
// 	{
// 		rotate(stack_a);
// 		rotate(stack_b);
// 		ft_putstr("rr\n");
// 	}
// 	if (stack_a->array[i] < stack_a->array[i + 1] && stack_b->array[i] > stack_b->array[i + 1])
// 	{
// 		rotate(stack_a);
// 		ft_putstr("ra\n");
// 	}
// 	if (stack_a->array[i] > stack_a->array[i + 1] && stack_b->array[i] < stack_b->array[i + 1])
// 	{
// 		rotate(stack_b);
// 		ft_putstr("rb\n");
// 	}
// 	if (stack_a->array[i] > stack_a->array[i + 1] && stack_b->array[i] > stack_b->array[i + 1])
// 	{
// 		swap(stack_a);
// 		swap(stack_b);
// 		ft_putstr("ss\n");
// 	}
// 	if (stack_a->array[i] > stack_a->array[i + 1] && stack_b->array[i] < stack_b->array[i + 1])
// 	{
// 		swap(stack_a);
// 		ft_putstr("sa\n");
// 	}
// 	if (stack_a->array[i] < stack_a->array[i + 1] && stack_b->array[i] > stack_b->array[i + 1])
// 	{
// 		swap(stack_b);
// 		ft_putstr("sb\n");
// 	}
// }
//
// void	sort_a_and_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	int		i;
//
// 	i = 0;
// 	while (check_sorted_params(stack_a) == 0 && check_sorted_params(stack_b) == 0)
// 	{
// 		while ((stack_a->array[0] > stack_a->array[1]) || (stack_b->array[0] > stack_b->array[1]))
// 		{
// 			check_two_first(stack_a, stack_b);
// 		}
// 		reverse_rotate(stack_a);
// 		reverse_rotate(stack_b);
// 		ft_putstr("rrr\n");
// 	}
// }
//
// void	quicksort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int		index_med;
// 	// int		med_small_a;
// 	// int		med_small_b;
//
//
// 	index_med = find_median(stack_a);
// 	divide_stack_a(index_med, stack_a, stack_b);
// 	// med_small_a = find_median(stack_a);
// 	// med_small_b = find_median(stack_b);
// 	// printf("med_small_a = %d    med_small_b = %d\n", stack_a->array[med_small_a], stack_b->array[med_small_b]);
// 	sort_a_and_b(stack_a, stack_b);
// 	ft_putstr("stack_a ---------\n");
// 	print_tab(stack_a);
// 	ft_putstr("stack_b ---------\n");
// 	print_tab(stack_b);
// }
