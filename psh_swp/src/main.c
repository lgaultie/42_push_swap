/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:20:51 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 11:14:49 by lgaultie         ###   ########.fr       */
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

void				final_free(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

/*
** check_sorted_params: check if the stack is already sorted. Returns -1 if it
** is sorted, and 0 if it's not.
*/

int					check_followed_params(t_stack *stack)
{
	int		i;
	int		j;

	if (stack->size < 1)
		return (-1);
	i = 0;
	while (i < stack->size - 1)
	{
		j = stack->array[i + 1];
		if (stack->array[i] == j - 1)
			i++;
		else
			return (i);
	}
	return (-1);
}

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

/*
** push_swap: decides which algo to use depending on the numbers of params.
*/

void				push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int		ret;

	ret = check_sorted_params(stack_a);
	if (stack_a->size == 2)
	{
		if (stack_a->array[0] > stack_a->array[1])
		{
			swap(stack_a);
			ft_putstr("sa\n");
		}
		return ;
	}
	else if (stack_a->size == 3)
		sort_three_last_numbers_on_a(stack_a);
	else if (stack_a->size <= 10 && ret > stack_a->size - 3 \
		&& ret < stack_a->size)
		small_reverse(ret, stack_a, stack_b);
	else if (stack_a->size <= 10)
		selection_sort(stack_a, stack_b);
	else if (stack_a->size <= 150)
		biglist1(stack_a, stack_b);
	else
		biglist(stack_a, stack_b);
}

/*
** create_stacks: create and initialize stack a & b.
*/

static void			create_stacks(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	if (!(stack_a = init_stack_a(stack_a, argc, argv)))
		return ;
	if (!(stack_b = ft_memalloc(sizeof(t_stack))))
	{
		free(stack_a);
		return ;
	}
	stack_b->size = 0;
	if (!(stack_b->array = ft_memalloc(sizeof(int) * stack_a->size)))
	{
		free(stack_a);
		free(stack_b);
		return ;
	}
	if (check_sorted_params(stack_a) == -1)
	{
		final_free(stack_a, stack_b);
		return ;
	}
	push_swap(stack_a, stack_b);
	final_free(stack_a, stack_b);
}

int					main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	create_stacks(argc, argv);
	return (0);
}
