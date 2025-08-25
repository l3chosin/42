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

}


void	open_window(int col, int row, t_node *map_array)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			scale;

	scale = 1;
	mlx = mlx_init(1920, 1080, "FdF", true);
	if (!mlx)
	{
		ft_printf("No se puedo inicializar MLX42\n");
		exit(EXIT_FAILURE);
	}
	img = mlx_new_image(mlx, col * scale, row * scale);
	img = draw_map(img, col, row, map_array);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
