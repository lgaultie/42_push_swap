/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:12:07 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/24 14:40:05 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	small_reverse(int ret, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		index_ret;

	i = 0;
	index_ret = stack_a->array[ret];
	while (stack_a->array[0] != index_ret)
	{
		i++;
		reverse_rotate(stack_a);
		ft_putstr("rra\n");
	}
	if (i == 2 && stack_a->array[0] > stack_a->array[1])
	{
		swap(stack_a);
		ft_putstr("sa\n");
		rotate(stack_a);
		ft_putstr("ra\n");
		rotate(stack_a);
		ft_putstr("ra\n");
		return ;
	}
	selection_sort(stack_a, stack_b);
}
