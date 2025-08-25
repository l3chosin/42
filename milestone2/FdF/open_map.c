/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:17:43 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/15 19:17:46 by aluther-         ###   ########.fr       */
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

int	col_counter(char *line)
{
	char	**tokens;
	char	*trimmed;
	int		columns;
	int		i;

	columns = 0;
	if (!line)
		return (0);
	trimmed = ft_strtrim(line, " \n");
	tokens = ft_split(trimmed, ' ');
	free(trimmed);
	i = 0;
	while (tokens[i])
	{
		columns++;
		i++;
	}
	free_split(tokens);
	return (columns);
}

int	row_counter(int fd, int col_expected)
{
	int		rows;
	int		check_col;
	char	*line;

	rows = 0;
	check_col = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_col = col_counter(line);
		if (check_col != col_expected)
		{
			rows++;
			ft_printf("Error! En linea %d: se esperaban %d col, pero hay %d\n",
				rows, col_expected, check_col);
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (rows);
}

int	open_map(int argc, char *argv[])
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("Uso: ./FDF maps/<mapa>\n", argc);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: No se pudo abrir el archivo %s\n", argv[1]);
		return (-1);
	}
	return (fd);
}

int	read_map_create_array(int argc, char *argv[], t_node **map_array, int *col)
{
	int	fd;
	int	row;

	fd = open_map(argc, argv);
	if (fd == -1)
		return (1);
	if (validate_map(fd, col, &row) == -1)
		return (close(fd), 1);
	close(fd);
	*map_array = malloc((*col) * row * sizeof(t_node));
	if (!*map_array)
		return (ft_printf("Error: malloc falló\n"), 1);
	data_assign(*map_array, *col, row, argv);
	return (row);
}
