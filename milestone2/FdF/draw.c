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

mlx_image_t	*draw_map(mlx_image_t *img, t_extra *map_extras, t_node *map_array)
{
	int	i;

	ft_printf("Escala %d\nOffsetX %d\nOffsetY %d\n", map_extras->scale,
		map_extras->offsetx, map_extras->offsety);
	i = 0;
	while (i < map_extras->total)
	{
		draw_line(img, map_array, map_extras, i);
		i++;
	}
	return (img);
}

void	open_window(t_extra *map_extras, t_node *map_array)
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
	img = draw_map(img, map_extras, map_array);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
