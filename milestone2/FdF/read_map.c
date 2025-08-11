/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:47:22 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/11 16:47:24 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	column_row_counter(int fd, int *column, int *row)
{
	int		i;
	char	*line;

	*column = 0;
	*row = 0;
	line = get_next_line(fd);
	if (!line)
		return ;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ')
			(*column)++;
		i++;
	}
	(*column)++;
	(*row)++;
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*row)++;
		free(line);
		line = get_next_line(fd);
	}
}

int	read_map(int argc, char *argv[], int *column, int *row)
{
	int	fd;
	int column;
	int row;

	if (argc < 2 && 2 < argc)
		ft_printf("Error! tienes %d argumentos. Necesitas 2!", argc);
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	column = 0;
	row = 0;
	column_row_counter(fd, int *column, int *row);

}
