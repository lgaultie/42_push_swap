/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:36:22 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/11 16:28:21 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** choose_pivot: returns index of the pivot, chosen with the 3-median method.
** this pivot has to be put at the end of the stack after.
*/

int			choose_pivot(t_stack *stack)
{
	int		i;
	// int		tmp;
	int		*tab;
	int		mid_index;
	int		index_pivot;

	i = 1;
	if (!(tab = ft_memalloc(sizeof(int) * 3)))
		return (-1);
	mid_index = stack->size / 2;
	tab[0] = stack->array[0];
	tab[1] = stack->array[mid_index];
	tab[2] = stack->array[stack->size - 1];
	// printf("tab[0] = %d   tab[1] = %d   tab[2] = %d tab[3] = %d\n", tab[0], tab[1], tab[2], tab[3]);
	if ((tab[0] > tab[1] && tab[0] < tab[2]) || (tab[0] < tab[1] && tab[0] > tab[2]))
		index_pivot = 0;
	if ((tab[1] > tab[0] && tab[1] < tab[2]) || (tab[1] < tab[0] && tab[1] > tab[2]))
		index_pivot = stack->size / 2;
	if ((tab[2] > tab[0] && tab[2] < tab[1]) || (tab[2] < tab[0] && tab[2] > tab[1]))
		index_pivot = stack->size - 1;

	// printf("tab[0] = %d  tab[1] = %d   tab[2] = %d\n", tab[0], tab[1],tab[2]);
	free(tab);
	return (index_pivot);
}

t_stack		*put_pivot_at_end(int index_pivot, t_stack *stack)
{
	int		pivot;

	pivot = stack->array[index_pivot];
	while (stack->array[stack->size - 1] != pivot)
	{
		if (index_pivot > stack->size / 2)
		{
			reverse_rotate(stack);
			// print_tab(stack);
			ft_putstr("rra\n");
		}
		else
		{
			rotate(stack);
			// print_tab(stack);
			ft_putstr("rra\n");
		}
	}
	return (stack);
}

t_stack		*swap_left_right(t_stack *stack)
{

}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int		index_pivot;

	(void)stack_b;
	print_tab(stack_a);
	index_pivot = choose_pivot(stack_a);
	// printf("pivot = stack_a[%d] = %d\n", index_pivot, stack_a->array[index_pivot]);
	stack_a = put_pivot_at_end(index_pivot, stack_a);
	stack_a = swap_left_right(stack_a);
	print_tab(stack_a);
}
