/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:36:22 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/11 14:25:17 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** choose_pivot: returns index of the pivot, chosen with the 3-median method.
** this pivot has to be put at the end of the stack after.
*/

//Cette methode fait des abort de temps en temps.
int			choose_pivot(t_stack *stack)
{
	int		tab[3];
	int		i;
	int		tmp;

	i = 0;
	tab[0] = stack->array[0];
	tab[1] = stack->array[((stack->size - 1) / 2) + 1];
	tab[2] = stack->array[stack->size - 1];
	printf("tab[1] = %d\n", tab[1]);
	while (i < 3)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
	}
	if (tab[1] == stack->array[(stack->size - 1) / 2])
		return (((stack->size - 1) / 2) + 1);
	if (tab[1] == stack->array[stack->size - 1])
		return (stack->size - 1);
	return (0);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int		index_pivot;
	(void)stack_b;

	index_pivot = choose_pivot(stack_a);
	// stack_a = put_pivot_at_end(stack_a);
	printf("index_pivot = %d\n", index_pivot);
}
