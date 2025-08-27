/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:24:50 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/20 16:24:52 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*draw_map(mlx_image_t *img, int col, int row, t_node *map_array)
{
	int	i;
	int	total;
	int	scale;

	scale = 10;
	total = row * col;
	i = 0;
	while (i < total)
	{
		mlx_put_pixel(img, (map_array[i].px) * scale + 100,
			(map_array[i].py) * scale + 100,
			map_array[i].color);

		i++;
	}
	return (img);
}


void	open_window(int col, int row, t_node *map_array)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920 + 480, 1080 + 270, "FdF", true);
	if (!mlx)
	{
		ft_printf("No se puedo inicializar MLX42\n");
		exit(EXIT_FAILURE);
	}
	img = mlx_new_image(mlx, 1920 + 480, 1080 + 270);
	img = draw_map(img, col, row, map_array);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
