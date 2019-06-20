/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:21:05 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/20 17:40:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include <stdio.h>

# define SA 1
# define SB 2
# define RA 4
# define RB 8
# define RRA 16
# define RRB 32

typedef struct	s_stack
{
	int			*array;
	int			instruc;
	int			size;
}				t_stack;

t_stack			*init_stack_a(t_stack *stack, int argc, char **argv);
long			modified_atoi(const char *str);
int				duplic(t_stack *stack, int index);
void			print_tab(t_stack *stack);
void			selection_sort(t_stack *stack_a, t_stack *stack_b);
t_stack			*sort_three_last_numbers_on_a(t_stack *stack);
t_stack			*sort_three_last_numbers_on_a2(t_stack *stack_a);
void			sort_b(t_stack *stack_b, t_stack *stack_a);
void			quicksort(t_stack *stack_a, t_stack *stack_b);
int				find_index_median(int median, int min, t_stack *stack);
void			calculate_max_value(t_stack *stack_b, t_stack *stack_a);
int				find_median(t_stack *stack);
int				find_median(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *from, t_stack *dest);
void			rotate(t_stack *stack);
void			swap(t_stack *stack);
void			free_tab(char **tab);
int				free_ret(t_stack *stack);
void			which_sort(t_stack *stack_a, t_stack *stack_b);
int				check_sorted_params(t_stack *stack);

#endif
