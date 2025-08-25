/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:28:30 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/17 17:28:32 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reset_fd(char *filename, int fd)
{
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: no se pudo reabrir el archivo %s\n", filename);
		return (-1);
	}
	return (fd);
}

int	scale_calculator(int col, int row)
{
	double	scale_w;
	double	scale_h;
	double	scale_tmp;
	int		scale;

	scale_w = 1920.0 / col;
	scale_h = 1080.0 / row;
	if (scale_w < scale_h)
		scale_tmp = scale_w;
	else
		scale_tmp = scale_h;
	scale = scale_tmp + 0.5;
	return (scale);
}
