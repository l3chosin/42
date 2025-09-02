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

int	scale_calculator(t_node *map_array, int total)
{
	double	scale_w;
	double	scale_h;
	int		scale;
	t_node	start;
	t_node	end;

	start = map_array[0];
	end = map_array[total - 1];
	scale_w = 1920.0 / (end.px - start.px);
	scale_h = 1080.0 / (end.py - start.py);
	if (scale_w < scale_h)
		scale = scale_w + 0.5;
	else
		scale = scale_h + 0.5;
	return (scale);
}

void	calculate_offset(t_node *map_array, t_extra *map_extras)
{
	t_node	start;
	t_node	end;

	start = map_array[0];
	end = map_array[map_extras->total - 1];
	map_extras->offsetx = (1920 - (end.px - start.px) * map_extras->scale) / 2;
	map_extras->offsety = (1080 - (end.py - start.py) * map_extras->scale) / 2;
}

void	iso_converter(t_node *map_array, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		map_array[i].px = (map_array[i].x - map_array[i].y)
			* cos(M_PI / 6);
		map_array[i].py = (map_array[i].x + map_array[i].y) * sin(M_PI / 6)
			- map_array[i].z * 0.15;
		i++;
	}

}

uint32_t	ft_strtoul(const char *str)
{
	uint32_t	result;

	result = 0;
	if (!str)
		return (0);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while ((*str >= '0' && *str <= '9')
		|| (*str >= 'a' && *str <= 'f')
		|| (*str >= 'A' && *str <= 'F'))
	{
		result *= 16;
		if (*str >= '0' && *str <= '9')
			result += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			result += *str - 'a' + 10;
		else
			result += *str - 'A' + 10;
		str++;
	}
	return (result);
}
