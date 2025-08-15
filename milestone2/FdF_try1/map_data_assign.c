/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:42:15 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/13 17:42:17 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hex_to_int(char *hex)
{
	int		value;
	int		i;

	value = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i])
	{
		value *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			value += hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			value += hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			value += hex[i] - 'a' + 10;
		i++;
	}
	return (value);
}

void	map_data_assign(int fd, t_node *map_array, int column, int row)
{
	char	*line;
	char	**tokens;
	char	**parts;
	int		r;
	int		c;

	r = 0;
	while (r < row)
	{
		line = get_next_line(fd);
		tokens = ft_split(line, ' ');
		c = 0;
		while (c < column)
		{
			parts = ft_split(tokens[c], ',');
			map_array[r * column + c].z = ft_atoi(parts[0]);
			if (parts[1])
				map_array[r * column + c].color = hex_to_int(parts[1]);
			free_split(parts);
			c++;
		}
		free_split(tokens);
		free(line);
		r++;
	}
}
