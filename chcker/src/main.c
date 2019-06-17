/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:30:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 19:26:43 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void			create_stacks(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	if (!(stack_a = init_stack_a(stack_a, argc, argv, argc)))
		return ;
	if (!(stack_b = ft_memalloc(sizeof(t_stack))))
		return ;
	if (!(stack_b->array = ft_memalloc(sizeof(int) * stack_a->size)))
		return ;
	stack_b->size = 0;
	stack_b->visu = stack_a->visu;
	if (read_input(stack_a, stack_b) == -1)
	{
		free_stack(stack_a, stack_b);
		ft_putstr("Error\n");
		return ;
	}
	if (check_order(stack_a, stack_b) == -1)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	both_visualization(stack_a, stack_b);
	free_stack(stack_a, stack_b);
}

int					main(int argc, char **argv)
{
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		return (0);
	if (argc <= 1)
		return (0);
	create_stacks(argc, argv);
	return (0);
}
