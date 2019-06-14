/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:38:55 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/14 11:43:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

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

/*
** count_visu: count the number of "-v" in the arguments so as to reduce argc,
** so I don't make too big malloc for my arrays.
*/

int		count_visu(int argc, char **argv)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			count++;
		i++;
	}
	return (count);
}

/*
** both_visualization: called at the end of the programm when "-v" is asked.
*/

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

void	push_visu(t_stack *from, t_stack *dest)
{
	if (from->visu == 1)
	{
		ft_putstr("------from------\n");
		visualization(from);
		ft_putstr("------dest------\n");
		visualization(dest);
	}
	return ;
}
