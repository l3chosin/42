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

void	open_window(int width, int heigth)
{
	mlx_t	*mlx;

	mlx = mlx_init(width, heigth, "FdF", true);
	if (!mlx)
	{
		ft_printf("No se puedo inicializar MLX42\n");
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
