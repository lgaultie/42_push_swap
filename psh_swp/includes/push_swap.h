/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:21:05 by lgaultie          #+#    #+#             */
/*   Updated: 2019/07/11 16:08:19 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct	s_data
{
	int			nb_push;
	int			nb_rotate;
}				t_data;

typedef struct	s_stack
{
	char		*buf;
	int			*array;
	int			size;
}				t_stack;

t_stack			*init_stack_a(t_stack *stack, int argc, char **argv);
long			modified_atoi(const char *str);
int				duplic(t_stack *stack, int index);
char			*ft_strjoinfree(char *s1, char *s2, int free_who);
void			selection_sort(t_stack *stack_a, t_stack *stack_b);
int				divide_stack_b(int index, t_stack *stack_a, t_stack *stack_b,
				int nb_push);
void			divide_stack_a(int index, t_stack *stack_a, t_stack *stack_b);
void			small_reverse(int ret, t_stack *stack_a, t_stack *stack_b);
t_stack			*sort_three_last_numbers_on_a(t_stack *stack);
t_stack			*sort_three_last_numbers_on_a2(t_stack *stack_a);
void			sort_b(t_stack *stack_b);
void			biglist1(t_stack *stack_a, t_stack *stack_b);
void			biglist(t_stack *stack_a, t_stack *stack_b);
int				find_index_median(int median, int min, t_stack *stack);
void			calculate_max_value(t_stack *stack_b, t_stack *stack_a);
void			opti_b(t_stack *stack_a, t_stack *stack_b);
int				find_median(t_stack *stack);
int				check_sorted_params_reverse(t_stack *stack);
int				find_small_numbers(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *from, t_stack *dest);
void			rotate(t_stack *stack);
void			swap(t_stack *stack);
void			free_tab(char **tab);
int				free_ret(t_stack *stack);
void			which_sort(t_stack *stack_a, t_stack *stack_b);
int				check_sorted_params(t_stack *stack);
void			write_instructions(char **tab);
int				check_followed_params(t_stack *stack);

#endif
