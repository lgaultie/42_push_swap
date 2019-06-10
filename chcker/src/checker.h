/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:35:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/10 12:52:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

typedef struct	s_stack
{
	int			visu;
	int			*array;
	int			size;
}				t_stack;

long			modified_atoi(const char *str);
int				read_input(t_stack *stack_a, t_stack *stack_b);
int				duplic(t_stack *stack, int index);
void			print_tab(t_stack *stack);
int				check_format(char *line);
void			apply_instruct(char *line, t_stack *a, t_stack *b);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *from, t_stack *dest);
int				check_order(t_stack *stack_a, t_stack *stack_b);
void			push_visu(t_stack *from, t_stack *dest);
void			visualization(t_stack *stack);
void			both_visualization(t_stack *stack_a, t_stack *stack_b);
void			free_stack(t_stack *stack_a, t_stack *stack_b);
t_stack			*free_wrong_list(t_stack *stack);
int				count_visu(int argc, char **argv);

#endif
