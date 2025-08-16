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
	int		columns;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	columns = 0;
	i = 0;
	while (tokens[i] != NULL)
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		rows++;
		check_col = col_counter(line);
		free(line);
		if (check_col != col_expected)
			return (ft_printf("Error! Mapa invalido"), -1);
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

int	read_map_create_array(int argc, char *argv[], t_node **map_array)
{
	int		fd;
	int		col;
	int		row;
	char	*line;


	fd = open_map(argc, argv);
	if (fd == -1)
		return (ft_printf("La apertura del archivo ha fallado\n"), 1);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("La lectura del archivo ha fallado\n"), close(fd), 1);
	col = col_counter(line);
	free(line);
	row = row_counter(fd, col);
	close(fd);
	if (row == -1)
		return (ft_printf("Error, columnas desiguales\n"), 1);
	*map_array = malloc(col * row * sizeof(t_node));
	if (!*map_array)
		return (ft_printf("Error: malloc falló\n"), 1);
	data_assign(*map_array, col, row, argv);
	print_map_array(*map_array, col, row);
	return (0);
}
