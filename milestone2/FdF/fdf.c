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

t_node	*make_the_array(int argc, char *argv[], int *column, int *row)
{
	t_node	*map_array;
	int		fd;
	int		check;

	check = read_map(argc, argv, column, row);
	if (check != 0)
		return (NULL);
	map_array = array_creator(*column, *row);
	if (!map_array)
		return (ft_printf("No se pudo crear el array"), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error al abrir el archivo");
		free(map_array);
		return (NULL);
	}
	map_data_assign(fd, map_array, *column, *row);
	close(fd);
	test_array(map_array, *column, *row);
	return (map_array);
}

int	start_window(t_node *map_array, int size, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920, 1080, argv[1], true);
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_pixels(map_array, size, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int column;
	int row;
	t_node *map;

	map = make_the_array(argc, argv, &column, &row);
	if (!map)
		return (1);
	start_window(map, column * row, argv);
	free(map);
	return (0);
}
