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
#include "mlx42/include/MLX42/MLX42.h"
#include <stdbool.h>
#include <stdlib.h>

int	make_the_array(int argc, char *argv[])
{
	int		column;
	int		row;
	t_node	*map_array;
	int		fd;
	int		check;

	check = read_map(argc, argv, &column, &row);
	if (check != 0)
		return (1);
	map_array = array_creator(column, row);
	if (!map_array)
		return (ft_printf("No se pudo crear el array"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error al abrir el archivo");
		free(map_array);
		return (1);
	}
	map_data_assign(fd, map_array, column, row);
	close(fd);
	test_array(map_array, column, row);
	free(map_array);
	return (0);
}

int	start_window(char *argv[])
{
	mlx_t	*mlx;

	mlx = mlx_init(1920, 1080, argv[1], true);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	make_the_array(argc, argv);
	start_window(argv);
	return (0);
}
