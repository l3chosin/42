/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:53:26 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/17 18:53:27 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_line(char *line, int expected_col, int row)
{
	int	col;

	if (!line)
		return (-1);
	col = col_counter(line);
	if (col != expected_col)
	{
		ft_printf("Error! la línea %d: se esperaban %d columnas, pero hay %d\n",
			row + 1, expected_col, col);
		return (-1);
	}
	return (0);
}

int	validate_map(int fd, int *out_col, int *out_row)
{
	char	*line;
	int		row;
	int		col;

	row = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	col = col_counter(line);
	while (line)
	{
		if (validate_line(line, col, row) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		row++;
		line = get_next_line(fd);
	}
	*out_col = col;
	*out_row = row;
	return (0);
}
