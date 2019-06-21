/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:23:52 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/21 11:54:23 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	write_instructions(char **tab)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (tab[i] != NULL)
	{
		size++;
		i++;
	}
	i = 0;
	while (i < size)
	{
		// printf("tab[%d] = %s\n",i,tab[i]);
		if (i > 0 && i < size - 1 && ft_strcmp(tab[i], "sa") == 0 \
			&& ft_strcmp(tab[i + 1], "sb") == 0)
		{
			ft_putstr("ss");
			i = i + 2;
		}
		else if (i > 0 && i < size - 1 && ft_strcmp(tab[i], "ra") == 0 \
			&& ft_strcmp(tab[i + 1], "rb") == 0)
		{
			ft_putstr("rr");
			i = i + 2;
		}
		else if (i > 0 && i < size - 1 && ft_strcmp(tab[i], "rra") == 0 \
			&& ft_strcmp(tab[i + 1], "rrb") == 0)
		{
			ft_putstr("rrr");
			i = i + 2;
		}
		else if (i > 0 && i < size - 1 && ft_strcmp(tab[i], "sb") == 0 \
			&& ft_strcmp(tab[i + 1], "sa") == 0)
		{
			ft_putstr("ss");
			i = i + 2;
		}
		else if (i > 0 && i < size - 1 && ft_strcmp(tab[i], "rb") == 0 \
			&& ft_strcmp(tab[i + 1], "ra") == 0)
		{
			ft_putstr("rr");
			i = i + 2;
		}
		else if (i > 0 && i < size - 1 && ft_strcmp(tab[i], "rrb") == 0 \
			&& ft_strcmp(tab[i + 1], "rra") == 0)
		{
			ft_putstr("rrr");
			i = i + 2;
		}
		else
		{
			while (tab[i][j] != '\0')
			{
				ft_putchar(tab[i][j]);
				j++;
			}
			i++;
		}
		ft_putchar('\n');
		j = 0;
	}
}
