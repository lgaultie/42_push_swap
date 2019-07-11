/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:16:29 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 16:23:35 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				find_minimum(t_stack *stack)
{
	int		min;
	int		i;

	i = 0;
	min = stack->array[i];
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

void			sort_last_one(t_stack *stack_a, t_stack *stack_b)
{
	int		min;

	min = find_minimum(stack_a);
	while (stack_a->array[0] != min)
	{
		rotate(stack_a);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "ra\n", 1)))
			return ;
	}
	push(stack_a, stack_b);
	if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "pb\n", 1)))
		return ;
}

void			big_opti(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	int		size_b_copy;
	int		nb_push;

	size_b_copy = stack_b->size;
	nb_push = 0;
	while (stack_b->size > size_b_copy / 2)
	{
		index_med = find_median(stack_b);
		nb_push = divide_stack_b(index_med, stack_a, stack_b, nb_push);
	}
	while (nb_push > 0)
	{
		index_med = find_median(stack_a);
		divide_stack_a(index_med, stack_a, stack_b);
		nb_push--;
	}
	if (check_followed_params(stack_a) != -1)
		sort_last_one(stack_a, stack_b);
}

void			biglist(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	char	**instruct;

	if (!(stack_b->buf = ft_strdup("")))
		return ;
	while (check_sorted_params(stack_a) != -1)
	{
		index_med = find_median(stack_a);
		divide_stack_a(index_med, stack_a, stack_b);
		if (stack_a->size == 3)
			sort_three_last(stack_a, stack_b);
	}
	big_opti(stack_a, stack_b);
	sort_three_last(stack_a, stack_b);
	while (stack_b->size > 0)
		calculate_max_value(stack_b, stack_a);
	if (!(instruct = ft_strsplit(stack_b->buf, '\n')))
	{
		free(stack_b->buf);
		return ;
	}
	write_instructions(instruct);
	free_tab(instruct);
	free(stack_b->buf);
}

void			biglist1(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	char	**instruct;

	if (!(stack_b->buf = ft_strdup("")))
		return ;
	while (check_sorted_params(stack_a) != -1)
	{
		index_med = find_median(stack_a);
		divide_stack_a(index_med, stack_a, stack_b);
		if (stack_a->size == 3)
			sort_three_last(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		calculate_max_value(stack_b, stack_a);
	if (!(instruct = ft_strsplit(stack_b->buf, '\n')))
	{
		free(stack_b->buf);
		return ;
	}
	write_instructions(instruct);
	free_tab(instruct);
	free(stack_b->buf);
}
