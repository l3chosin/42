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
	int i = 0;

	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	column_row_counter(int fd, int *column, int *row)
{
	char	*line;
	char	**tokens;
	int	count;

	*column = 0;
	*row = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		tokens = ft_split(line, ' ');
		count = 0;
		while (tokens[count])
			count++;
		*column = count;
		*row = 1;
		free_split(tokens);
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		(*row)++;
		free(line);
	}
}

int	read_map(int argc, char *argv[], int *column, int *row)
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error! tienes %d argumentos. Necesitas 2!", argc);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: No se pudo abrir el archivo %s\n", argv[1]);
		return (-1);
	}
	*column = 0;
	*row = 0;
	column_row_counter(fd, column, row);
	close(fd);
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
