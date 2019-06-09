/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:30:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/09 18:08:17 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		read_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret != 0)
	{
		if (line)
			free(line);
		ret = get_next_line(0, &line);
		if (check_format(line) == -1)
		{
			if (line)
				free(line);
			return (-1);
		}
		apply_instruct(line, stack_a, stack_b);
	}
	return (0);
}

t_stack		*initalize_stack_a(int argc, char **argv)
{
	t_stack		*stack;
	int			i;
	int			x;
	long		ret;
	int			visu;

	i = 1;
	x = 0;
	visu = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
		{
			visu = 1;
			argc--;
		}
		i++;
	}
	i = 1;
	if (!(stack = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->array = ft_memalloc(sizeof(int) * argc - 1)))
		return (NULL);
	stack->size = argc - 1;
	stack->visu = visu;
	while (i < argc + visu)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			i++;
		ret = modified_atoi(argv[i]);
		stack->array[x] = ret;
		// printf("argv[%d] = %s  argc = %d \n", i, argv[i], argc);
		// printf("stack[%d] = %d  argc = %d \n", x, stack->array[x], argc);
		if (ret > 2147483647 || ret < -2147483648 \
			|| check_duplicates(stack, x) == -1)
		{
			ft_putstr("Error\n");
			free(stack->array);
			free(stack);
			return (NULL);
		}
		x++;
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

void	create_stacks(int argc, char **argv)
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
	if (stack_a->visu == 1)
	{
		ft_putstr("STACK A\n");
		print_tab(stack_a);
		ft_putstr("------------\n");
		ft_putstr("STACK B\n");
		print_tab(stack_b);
	}
	free_stack(stack_a, stack_b);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		return (0);
	if (argc <= 1)
		return (0);
	create_stacks(argc, argv);
	return (0);
}
