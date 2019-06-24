/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:23:52 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/24 17:56:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	calcul_tab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

static int	if_ss(int i, int size, char **t)
{
	int		ss;

	ss = 0;
	if ((i > 0 && i < size - 1 && ft_strcmp(t[i], "sa") == 0 \
		&& ft_strcmp(t[i + 1], "sb") == 0) || (i > 0 && i < size - 1 \
		&& ft_strcmp(t[i], "sb") == 0 && ft_strcmp(t[i + 1], "sa") == 0))
		ss = 1;
	return (ss);
}

static int	if_rr(int i, int size, char **t)
{
	int		rr;

	rr = 0;
	if ((i > 0 && i < size - 1 && ft_strcmp(t[i], "ra") == 0 \
		&& ft_strcmp(t[i + 1], "rb") == 0) || (i > 0 && i < size - 1 \
		&& ft_strcmp(t[i], "rb") == 0 && ft_strcmp(t[i + 1], "ra") == 0))
		rr = 1;
	return (rr);
}

static int	if_rrr(int i, int size, char **t)
{
	int		rrr;

	rrr = 0;
	if ((i > 0 && i < size - 1 && ft_strcmp(t[i], "rra") == 0 \
		&& ft_strcmp(t[i + 1], "rrb") == 0) || (i > 0 && i < size - 1 \
		&& ft_strcmp(t[i], "rrb") == 0 && ft_strcmp(t[i + 1], "rra") == 0))
		rrr = 1;
	return (rrr);
}

void		write_instructions(char **t)
{
	int		i;
	int		size;
	int		ss;
	int		rr;
	int		rrr;

	i = 0;
	size = calcul_tab_size(t);
	while (i < size)
	{
		if ((ss = if_ss(i, size, t)) == 1)
			ft_putstr("ss");
		else if ((rr = if_rr(i, size, t)) == 1)
			ft_putstr("rr");
		else if ((rrr = if_rrr(i, size, t)) == 1)
			ft_putstr("rrr");
		else
		{
			ft_putstr(t[i]);
			i++;
		}
		if (ss == 1 || rr == 1 || rrr == 1)
			i = i + 2;
		ft_putchar('\n');
	}
}
