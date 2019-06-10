/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:21:05 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/10 16:58:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../../libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int			*array;
	int			size;
}				t_stack;

long			modified_atoi(const char *str);
int				duplic(t_stack *stack, int index);
void			print_tab(t_stack *stack);
void 			selection_sort(t_stack *stack_a, t_stack *stack_b);
void			quicksort(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *from, t_stack *dest);
void			rotate(t_stack *stack);
void			swap(t_stack *stack);

#endif
