/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:16:29 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/24 16:14:29 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		sort_tree_last(t_stack *s, t_stack *stack_b)
{
	if (s->array[0] > s->array[1] && s->array[1] < s->array[2] \
		&& s->array[0] < s->array[2])
	{
		swap(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "sa\n", 1)))
			return ;
	}
	else if (s->array[0] > s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] > s->array[2])
	{
		swap(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "sa\n", 1)))
			return ;
		reverse_rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
			return ;
	}
}

static void		sort_three_last(t_stack *s, t_stack *stack_b)
{
	if (s->array[0] < s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] > s->array[2])
	{
		reverse_rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\n", 1)))
			return ;
	}
	else if (s->array[0] < s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] < s->array[2])
	{
		reverse_rotate(s);
		swap(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "rra\nsa\n", 1)))
			return ;
	}
	else if (s->array[0] > s->array[1] && s->array[1] < s->array[2] \
		&& s->array[0] > s->array[2])
	{
		rotate(s);
		if (!(stack_b->buf = ft_strjoinfree(stack_b->buf, "ra\n", 1)))
			return ;
	}
	else
		sort_tree_last(s, stack_b);
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
