/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:36:44 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/14 12:30:08 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		check_no_int(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != ' ' && str[i] != '-' \
			&& str[i] != '+')
			return (-1);
		i++;
	}
	return (0);
}

static int		check_solo_minus(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && (str[i + 1] < 48 || str[i + 1] > 57))
			return (-1);
		i++;
	}
	return (0);
}

/*
** modified_atoi: my ft_atoi does the overflow when going over max_int or
** min_int, here I need to return -1 in such case.
*/

long			modified_atoi(const char *str)
{
	int			i;
	int			stock;
	size_t		res;

	i = 0;
	res = 0;
	stock = 1;
	if (check_no_int(str) == -1 || check_solo_minus(str) == -1)
		return (2147483648);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	stock = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (stock == 1 && res > 2147483647)
			return (2147483648);
		if (stock == -1 && res > (size_t)2147483647 + 1)
			return (2147483648);
		i++;
	}
	res = res * stock;
	return (res);
}

/*
** duplic: checks for forbidden duplicates in the arguments.
*/

int				duplic(t_stack *stack, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (stack->array[i] == stack->array[index])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
