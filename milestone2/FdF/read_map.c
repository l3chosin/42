#include "fdf.h"

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
		if (line[i] == ' ' && line[i+1] != ' ' && line[i+1] != '\n')
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

int	column_row_tester(int argc, char *argv[])
{
	int	column;
	int	row;
	int result;

	ft_printf("=== Probador de lectura de mapas ===\n");
	result = read_map(argc, argv, &column, &row);
	if (result == -1)
	{
		ft_printf("Error al leer el mapa.\n");
		return(1);
	}
	ft_printf("\n=== Resultados ===\n");
    ft_printf("Columnas: %d\n", column);
    ft_printf("Filas: %d\n", row);
    ft_printf("Total de elementos: %d\n", column * row);
    return (0);
}
