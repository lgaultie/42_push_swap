/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:23:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/14 11:43:44 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int			read_input(t_stack *stack_a, t_stack *stack_b)
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
