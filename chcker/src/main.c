/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:30:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 18:49:34 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack		*create_stack_a(int argc, int visu)
{
	t_stack		*stack;

	if (!(stack = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->array = ft_memalloc(sizeof(int) * argc - 1)))
		return (NULL);
	stack->size = argc - 1;
	stack->visu = visu;
	return (stack);
}

static t_stack		*initalize_stack_a(int argc, char **argv)
{
	t_stack		*stack;
	int			i;
	int			x;
	long		ret;
	int			visu;

	i = 1;
	x = 0;
	visu = display_or_not(argc, argv);
	if (visu == 1)
		argc--;
	if ((stack = create_stack_a(argc, visu)) == NULL)
		return (NULL);
	while (i < argc + visu)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			i++;
		ret = modified_atoi(argv[i]);
		stack->array[x] = ret;
		if (ret > 2147483647 || ret < -2147483648 || duplicates(stack, x) == -1)
			return (free_wrong_list(stack));
		x++;
		i++;
	}
	return (stack);
}

static void			create_stacks(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (!(stack_a = initalize_stack_a(argc, argv)))
		return ;
	if (!(stack_b = ft_memalloc(sizeof(t_stack))))
		return ;
	if (!(stack_b->array = ft_memalloc(sizeof(int) * argc - 1)))
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
