/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:38:55 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 18:44:38 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		display_or_not(int argc, char **argv)
{
	int		i;
	int		visu;

	i = 1;
	visu = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			visu = 1;
		i++;
	}
	return (visu);
}

void	both_visualization(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->visu == 1)
	{
		ft_putstr("STACK A\n");
		print_tab(stack_a);
		ft_putstr("------------\n");
		ft_putstr("STACK B\n");
		print_tab(stack_b);
	}
}

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
