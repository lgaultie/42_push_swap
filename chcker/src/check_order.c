/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:31:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 17:19:22 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_order(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	if (stack_b->size > 0)
		return (-1);
	i = 0;
	while (i < stack_a->size - 2)
	{
		// printf("stack[%d] = %d stack[%d] = %d\n", i, stack_a[i], i+1, stack_a[i+1]);
		if (stack_a->array[i] > stack_a->array[i + 1])
			return (-1);
		i++;
	}
	return (0);
}
