/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:31:49 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/02 10:31:51 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham_step(t_bresenham *b)
{
	b->e2 = 2 * b->err;
	if (b->e2 >= b->dy)
	{
		b->err += b->dy;
		b->x0 += b->sx;
	}
	if (b->e2 <= b->dx)
	{
		b->err += b->dx;
		b->y0 += b->sy;
	}
}

static void	draw_line_points(mlx_image_t *img, t_node p0,
			t_node p1, t_extra *map_extras)
{
	t_bresenham	b;

	b.x0 = (int)(p0.px * map_extras->scale + map_extras->offsetx);
	b.y0 = (int)(p0.py * map_extras->scale + map_extras->offsety);
	b.x1 = (int)(p1.px * map_extras->scale + map_extras->offsetx);
	b.y1 = (int)(p1.py * map_extras->scale + map_extras->offsety);
	b.dx = abs(b.x1 - b.x0);
	b.dy = -abs(b.y1 - b.y0);
	b.sx = (b.x0 < b.x1) - (b.x0 > b.x1);
	b.sy = (b.y0 < b.y1) - (b.y0 > b.y1);
	b.err = b.dx + b.dy;
	while (1)
	{
		put_pixel_safe(img, b.x0, b.y0, p0.color);
		if (b.x0 == b.x1 && b.y0 == b.y1)
			break ;
		bresenham_step(&b);
	}
}

void	draw_line(mlx_image_t *img, t_node *map_array,
			t_extra *map_extras, int index)
{
	int		x;
	int		y;

	if (index >= map_extras->total)
		return ;
	x = index % map_extras->col;
	y = index / map_extras->col;
	if (x < map_extras->col - 1)
		draw_line_points(img, map_array[index],
			map_array[index + 1], map_extras);
	if (y < map_extras->row - 1)
		draw_line_points(img, map_array[index],
			map_array[index + map_extras->col], map_extras);
}
