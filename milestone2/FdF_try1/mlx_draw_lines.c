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

void	draw_pixels_and_lines(t_node *map_array, int column, int row, mlx_image_t *img)
{
	int	i;
	int	j;
	int	scale;
	int idx;
	int idx_right;
	int idx_down;

	j = 0;
	scale = 2;
	while (j < row)
	{
		i = 0;
		while (i < column)
		{
            idx = j * column + i;
            mlx_image_t (img,
                map_array[idx].x * scale,
                map_array[idx].y * scale,
                map_array[idx].z * scale,
                map_array[idx].color);
            if (i < column - 1)
                idx_right = idx + 1;
            if (j < row - 1)
                idx_down = idx + column;
            i++;
		}
		j++;
	}
}
