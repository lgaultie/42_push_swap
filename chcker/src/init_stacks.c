/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:31:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 19:27:14 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int		calculate_argc(int argc, char **argv, int j)
{
	int			i;
	char		**tab;
	int			cpy_argc;

	i = 1;
	cpy_argc = argc;
	while (i < cpy_argc)
	{
		if (argv[i] != NULL && ft_strcmp(argv[i], "-v") != 0)
		{
			if (ft_strchr(argv[i], ' '))
			{
				tab = ft_strsplit(argv[i], ' ');
				while (tab[j] != NULL)
				{
					argc++;
					j++;
				}
				free_tab(tab);
			}
		}
		i++;
	}
	return (argc);
}

static t_stack	*create_stack_a(int argc, int visu, char **argv)
{
	int			j;
	t_stack		*stack;

	j = 0;
	argc = calculate_argc(argc, argv, j);
	if (!(stack = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->array = ft_memalloc(sizeof(int) * (argc - 1))))
		return (NULL);
	stack->size = argc - 1;
	stack->visu = visu;
	return (stack);
}

static int		no_quote(int i, char **argv, int x, t_stack *stack)
{
	long		ret;

	if (!(ft_strchr(argv[i], ' ')))
	{
		ret = modified_atoi(argv[i]);
		stack->array[x] = ret;
		if (ret > 2147483647 || ret < -2147483648 \
			|| duplic(stack, x) == -1)
			return (free_wrong_list(stack));
		x++;
	}
	return (x);
}

static int		case_of_quote(int i, char **argv, int x, t_stack *stack)
{
	char		**tab;
	int			j;
	long		ret;

	j = 0;
	if (ft_strchr(argv[i], ' '))
	{
		tab = ft_strsplit(argv[i], ' ');
		while (tab[j] != NULL)
		{
			ret = modified_atoi(tab[j]);
			stack->array[x] = ret;
			if (ret > 2147483647 || ret < -2147483648 || duplic(stack, x) == -1)
			{
				free_tab(tab);
				return (free_wrong_list(stack));
			}
			j++;
			x++;
		}
		free_tab(tab);
		stack->size--;
	}
	return (x);
}

t_stack			*init_stack_a(t_stack *stack, int argc, char **argv, int i)
{
	int			x;
	int			visu;
	int			count;

	i = 1;
	x = 0;
	count = count_visu(argc, argv);
	visu = (count > 0) ? 1 : 0;
	argc = argc - count;
	if ((stack = create_stack_a(argc, visu, argv)) == NULL)
		return (NULL);
	while (i < argc + count)
	{
		if (argv[i] != NULL && ft_strcmp(argv[i], "-v") != 0)
		{
			if ((x = case_of_quote(i, argv, x, stack)) == -1)
				return (NULL);
			if ((x = no_quote(i, argv, x, stack)) == -1)
				return (NULL);
		}
		i++;
	}
	return (stack);
}
