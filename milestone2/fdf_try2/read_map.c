/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:31:31 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/13 16:31:33 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	validate_columns(char *line, int expected)
{
	char	**tokens;
	int		count;

	tokens = ft_split(line, ' ');
	count = 0;
	while (tokens[count])
		count++;
	free_split(tokens);
	if (expected > 0 && count != expected)
		return (0);
	return (count);
}

int	column_row_counter(int fd, int *column, int *row)
{
	char	*line;
	int		count;

	*column = 0;
	*row = 0;
	line = get_next_line(fd);
	while (line)
	{
		count = validate_columns(line, *column);
		if (count == 0)
		{
			ft_printf("Error: el mapa tiene diferentes columnas\n");
			return (0);
		}
		if (*column == 0)
			*column = count;
		(*row)++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

t_node	*array_creator(int column, int row)
{
	t_node	*map_array;
	int		i;
	int		row_tmp;
	int		col_tmp;

	map_array = malloc(column * row * sizeof(t_node));
	if (!map_array)
		return (free(map_array), NULL);
	row_tmp = 0;
	col_tmp = 0;
	while (row_tmp < row)
	{
		col_tmp = 0;
		while (col_tmp < column)
		{
			i = row_tmp * column + col_tmp;
			map_array[i].x = col_tmp;
			map_array[i].y = row_tmp;
			map_array[i].z = 0;
			map_array[i].color = 0xFFFFFF;
			col_tmp++;
		}
		row_tmp++;
	}
	return (map_array);
}
