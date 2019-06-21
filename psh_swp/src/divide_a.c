/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:25:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/21 16:05:42 by lgaultie         ###   ########.fr       */
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
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "pb\n", 1)))
				return ;
			sort_b(stack_b);
		}
		else if (index_push <= stack_a->size / 2)
		{
			rotate(stack_a);
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "ra\n", 1)))
				return ;
		}
		else if (index_push > stack_a->size / 2)
		{
			reverse_rotate(stack_a);
			if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
				return ;
		}
	}
}

t_stack			*sort_tree_last(t_stack *s, t_stack *stack_b)
{
	if (s->array[0] > s->array[1] && s->array[1] < s->array[2] \
		&& s->array[0] < s->array[2])
	{
		swap(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "sa\n", 1)))
			return (NULL);
	}
	else if (s->array[0] > s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] > s->array[2])
	{
		swap(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "sa\n", 1)))
			return (NULL);
		reverse_rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
			return (NULL);
	}
	return (s);
}

t_stack			*sort_three_last(t_stack *s, t_stack *stack_b)
{
	if (s->array[0] < s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] > s->array[2])
	{
		reverse_rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
			return (NULL);
	}
	else if (s->array[0] < s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] < s->array[2])
	{
		reverse_rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
			return (NULL);
		swap(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "sa\n", 1)))
			return (NULL);
	}
	else if (s->array[0] > s->array[1] && s->array[1] < s->array[2] \
		&& s->array[0] > s->array[2])
	{
		rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "ra\n", 1)))
			return (NULL);
	}
	else
		s = sort_tree_last(s, stack_b);
	return (s);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
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
