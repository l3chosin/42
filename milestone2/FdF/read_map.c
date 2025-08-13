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
		if (line[i] == ' ' && line[i+1] != ' ')
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
