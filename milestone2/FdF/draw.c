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

void open_window(int width, int heigth, char *argv[])
{
	mlx_t	*mlx;

	mlx = mlx_init(width, heigth, ft_strchr(argv[1], '/'), true);
	mlx_loop(mlx);
}

void pixel_to_window(t_node **map, mlx_image_t *img, mlx_t *mlx)
{
    int i;

    i = 0;

    if (!map || !img || !mlx)
        return;
    while (map[i] != NULL)
    {
        if (map[i]->x >= 0 && map[i]->x < img->width &&
            map[i]->y >= 0 && map[i]->y < img->height)
        {
            mlx_put_pixel(img, map[i]->x, map[i]->y, map[i]->color);
        }
        i++;
    }
    mlx_image_to_window(mlx, img, 0, 0);
}
