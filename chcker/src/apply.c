/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:44:29 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 18:48:57 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		apply_swap(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
}

static void		apply_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
}

static void		apply_reverse_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void			apply_instruct(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push(a, b);
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 \
		|| ft_strcmp(line, "ss") == 0)
		apply_swap(line, a, b);
	else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0 \
		|| ft_strcmp(line, "rr") == 0)
		apply_rotate(line, a, b);
	else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 \
		|| ft_strcmp(line, "rrr") == 0)
		apply_reverse_rotate(line, a, b);
}
