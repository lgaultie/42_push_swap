/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:23:21 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 16:24:37 by lgaultie         ###   ########.fr       */
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

void			sort_three_last(t_stack *s, t_stack *stack_b)
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
