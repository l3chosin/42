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
#include "libft/libft.h"
#include <stdlib.h>

int	col_counter(char *line)
{
	char	**tokens;
	int		columns;
	int		i;

	tokens = ft_split(line, ' ');
	i = 0;
	while (tokens[i] != NULL && i++)
		columns++;
	return (columns);
}

int	row_counter(int fd, int col_expected)
{
	int		rows;
	int		check_col;
	char	*line;

	rows = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		row++;
		check_col = col_counter(line);
		if (check_col != col_expected)
			return (-1);
		get_next_line(fd);
	}
}

int	open_map(int argc, char *argv[])
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
	return (fd);
}

int	read_map_create_array(int argc, char *argv[])
{
	int		fd;
	int		col;
	int		row;
	char	*line;
	t_node	*map_array;


	fd = open_map(argc, argv);
	if (fd == -1)
		return (ft_printf("La apertura del archivo ha fallado"), 1);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("La lectura del archivo ha fallado"), 1);
	col = col_counter(line);
	row = row_counter(fd, col);
	if (row == -1)
		return (ft_printf("Error, columnas desiguales"), 1);
	map_array = malloc(col * row * sizeof(t_node));



	close(fd);
	return (0);
}
