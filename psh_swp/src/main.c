/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:20:51 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 10:42:43 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** check_sorted_params: check if the stack is already sorted. Returns -1 if it
** is sorted, and 0 if it's not.
*/

int					check_sorted_params(t_stack *stack)
{
	int		i;

	if (stack->size < 1)
		return (-1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] < stack->array[i + 1])
			i++;
		else
			return (i);
	}
	return (-1);
}

void				push_swap(t_stack *stack_a, t_stack *stack_b)
{
	// if (stack_a->size <= 10)
		// which_sort(stack_a, stack_b);
	// else
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
	if (!(stack_b->array = ft_memalloc(sizeof(int) * stack_a->size)))
		return ;
	if (check_sorted_params(stack_a) == -1)
	{
		free(stack_a->array);
		free(stack_a);
		free(stack_b->array);
		free(stack_b);
		return ;
	}
	push_swap(stack_a, stack_b);

	// ft_putstr("stack_a--------\n");/////////////////////////////////////////
	// print_tab(stack_a);/////////////////////////////////////////////////////
	// ft_putstr("stack_b--------\n");/////////////////////////////////////////
	// print_tab(stack_b);/////////////////////////////////////////////////////

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
