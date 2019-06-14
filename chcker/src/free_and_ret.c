/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:26:31 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/14 15:29:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int			free_wrong_list(t_stack *stack)
{
	ft_putstr("Error\n");
	free(stack->array);
	free(stack);
	return (-1);
}

void		free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
