/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:51:26 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/11 14:51:29 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int i;
	int lenght;

	lenght = 200;
	i = 0;
	mlx = mlx_init(1920, 1080, "testing", false);
	if (!mlx)
	{
		return (EXIT_FAILURE);
	}
	img = mlx_new_image(mlx, 256, 256);
	if (!img)
		return (EXIT_FAILURE);
	while (i < lenght)
	{
		mlx_put_pixel(img, i, i, 0xffffffff);
		i++;
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
