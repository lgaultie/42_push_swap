/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:16:29 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/10 17:18:21 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	print_tab(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(stack->array[i]);
		ft_putchar('\n');
		i++;
	}
}


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

int		find_minimum(t_stack *stack)
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

void			biglist(t_stack *stack_a, t_stack *stack_b)
{
	int		index_med;
	char	**instruct;
	int		i;
	int		size_b_copy;
	int		nb_push;
	int		min;

	i = 0;
	if (!(stack_b->buf = ft_strdup("")))
		return ;
	while (check_sorted_params(stack_a) != -1)
	{
		index_med = find_median(stack_a);
		divide_stack_a(index_med, stack_a, stack_b);
		if (stack_a->size == 3)
			sort_three_last(stack_a, stack_b);
		i++;
	}
	size_b_copy = stack_b->size;
	nb_push = 0;
	while (stack_b->size > size_b_copy / 3)
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
		{
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
