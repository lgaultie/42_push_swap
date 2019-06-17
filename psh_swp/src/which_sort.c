/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:53:52 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 10:45:49 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		inverse_sort(t_stack *stack_a, t_stack *stack_b)
{
	//mettre les chiffres ou ca merde en haut de la liste puis les push
	//on aura une liste a avec des petit chiffres triés
	//et une liste b avec une liste de plus gros chiffres dans le desordre
	//faire selection sort sur b?
	(void)stack_a;
	(void)stack_b;
}



void		which_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		index_not_sorted;
	int		median;

	median = find_median(stack_a);
	index_not_sorted = check_sorted_params(stack_a);
	// printf("median a index = %d  stack_a->array[%d] = %d\n", stack_a->array[median], index_not_sorted, stack_a->array[index_not_sorted]);
	//si a partir du moment ou ca foire c'est sur la fin de la liste finale, faut
	//faire autrement, push sur b a partir de la fin plutot, ce sera plus opti
	if (index_not_sorted < stack_a->array[median])
		selection_sort(stack_a, stack_b);
	if (index_not_sorted >= stack_a->array[median])
		inverse_sort(stack_a, stack_b);

}
