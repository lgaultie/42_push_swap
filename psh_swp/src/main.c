/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:20:51 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/10 18:04:25 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack		*init_stack_a(t_stack *stack, int argc, char **argv)
{
	int			i;
	int			x;
	long		ret;

	i = 1;
	x = 0;
	if (!(stack = ft_memalloc(sizeof(t_stack))))
	return (NULL);
	if (!(stack->array = ft_memalloc(sizeof(int) * argc - 1)))
	return (NULL);
	stack->size = argc - 1;
	while (i < argc)
	{
		ret = modified_atoi(argv[i]);
		stack->array[x] = ret;
		if (ret > 2147483647 || ret < -2147483648 || duplic(stack, x) == -1)
		{
			ft_putstr("Error\n");
			free(stack->array);
			free(stack);
			return (NULL);
		}
		x++;
		i++;
	}
	return (stack);
}

void				push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 10)
		selection_sort(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);
}

static void			create_stacks(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	if (!(stack_a = init_stack_a(stack_a, argc, argv)))
		return ;
	if (!(stack_b = ft_memalloc(sizeof(t_stack))))
		return ;
	stack_b->size = 0;
	if (!(stack_b->array = ft_memalloc(sizeof(int) * argc - 1)))
		return ;
	push_swap(stack_a, stack_b);

	ft_putstr("stack_a--------\n");////////////////////////////////////////////
	print_tab(stack_a);////////////////////////////////////////////////////////
	ft_putstr("stack_b--------\n");////////////////////////////////////////////
	print_tab(stack_b);////////////////////////////////////////////////////////

	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

int			main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	create_stacks(argc, argv);
	return (0);
}
