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

void	draw_pixels(t_node *map_array, int size, mlx_image_t *img)
{
	int i;

	i = 0;
	while (i < size)
	{
		mlx_put_pixel(img, map_array[i].x , map_array[i].y , map_array[i].color);
		i++;
	}
}
