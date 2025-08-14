/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:27:16 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/14 13:27:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx42/include/MLX42/MLX42.h"

void	draw_pixels(t_node *map_array, int size, mlx_image_t *img)
{
	int	i;
	int j;
	int	scale;
	int	displace;

	i = 0;
	scale = 5;
	displace = 100;
	while (i < size)
	{
		mlx_put_pixel(img, map_array[i].x * scale + displace , map_array[i].y * scale + displace , map_array[i].color);
		j = 0;
		while(j < map_array[i].x * scale + displace)
		{
			mlx_put_pixel(img, map_array[j].x, map_array[j].y, map_array[j].color);
			j++;
		}
		i++;
	}
}
