/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:38:43 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 18:03:24 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** swap: swap the first 2 elements at the top of stack.
** Do nothing if there is only one or no elements.
*/

void	swap(t_stack *stack)
{
	int		tmp;

	// printf("argc = %d\n", argc);
	if (stack->size <= 2)
		return ;
	else
	{
		tmp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = tmp;
	}
	visualization(stack);
}

/*
** rotate: shift up all elements of a stack by 1.
** The first element becomes the last one.
*/

void	rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	// printf("argc = %d\n", argc);
	if (stack->size <= 2)
		return ;
	tmp = stack->array[0];
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	visualization(stack);
}

/*
** reverse_rotate: shift down all elements of a stack by 1.
** The last element becomes the first one.
*/

void	reverse_rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	i = stack->size - 1;
	if (stack->size <= 2)
		return ;
	tmp = stack->array[i];
	// printf("tmp = %d   stack->size = %d\n",tmp, stack->size);
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = tmp;
	visualization(stack);
}

/*
** push: take the first element at the top of 'from' and put it at the top of
** 'dest'. Do nothing if 'from' is empty.
*/

void	push(t_stack *from, t_stack *dest)
{
	int		i;

	i = 0;
	// printf("from->size = %d   dest->size = %d\n", from->size, dest->size);
	if (from->size < 1)
		return;
	dest->size++;
	if (dest->size > 1)
	{
		i = dest->size;
		while (i > 0)
		{
			dest->array[i] = dest->array[i - 1];
			i--;
		}
	}
	dest->array[0] = from->array[0];
	from->size--;
	while (i < from->size)
	{
		from->array[i] = from->array[i + 1];
		i++;
	}
	visualization(from);
	visualization(dest);
}
