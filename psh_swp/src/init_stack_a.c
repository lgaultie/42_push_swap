/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:55:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/16 11:28:53 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*create_stack_a(int argc, char **argv)
{
	t_stack		*stack;
	int			i;
	int			j;
	char		**tab;
	int			cpy_argc;

	i = 1;
	j = 0;
	cpy_argc = argc;
	while (i < cpy_argc)
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
		i++;
	}
	if (!(stack = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->array = ft_memalloc(sizeof(int) * argc - 1)))
		return (NULL);
	stack->size = argc - 1;
	return (stack);
}

static int		no_quote(int i, char **argv, int x, t_stack *stack)
{
	long		ret;

	if (!(ft_strchr(argv[i], ' ')))
	{
		ret = modified_atoi(argv[i]);
		stack->array[x] = ret;
		if (ret > 2147483647 || ret < -2147483648 || duplic(stack, x) == -1)
		{
			ft_putstr("Error\n");
			free(stack->array);
			free(stack);
			return (-1);
		}
		x++;
	}
	return (x);
}

static int			case_of_quote(int i, char **argv, int x, t_stack *stack)
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
				ft_putstr("Error\n");
				free(stack->array);
				free(stack);
				return (-1);
			}
			j++;
			x++;
		}
		free_tab(tab);
		stack->size--;
	}
	return (x);
}

t_stack				*init_stack_a(t_stack *stack, int argc, char **argv)
{
	int			i;
	int			x;

	i = 1;
	x = 0;
	if ((stack = create_stack_a(argc, argv)) == NULL)
		return (NULL);
	while (i < argc)
	{
		if ((x = case_of_quote(i, argv, x, stack)) == -1)
			return (NULL);
		if ((x = no_quote(i, argv, x, stack)) == -1)
			return (NULL);
		i++;
	}
	// print_tab(stack);
	return (stack);
}
