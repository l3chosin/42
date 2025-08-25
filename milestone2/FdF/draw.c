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

void	open_window(int width, int heigth, char *argv[])
{
	mlx_t	*mlx;

	mlx = mlx_init(width, heigth, ft_strchr(argv[1], '/'), true);
	mlx_loop(mlx);
}
