/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:38:55 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 17:30:16 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	visualization(t_stack *stack)
{
	if (stack->visu == 1)
		print_tab(stack);
}

void	print_tab(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		printf("tab[%d] = %d\n", i, stack->array[i]);
		i++;
	}
}
