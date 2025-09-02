/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:47:22 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/11 16:47:24 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_node	*map;
	t_extra	map_extras;
	int		col;
	int		row;

	col = 0;
	row = read_map_create_array(argc, argv, &map, &col);
	if (col == 0)
		return (ft_printf("This shit ain't good\n"), 1);
	map_extras.map_array = map;
	map_extras.col = col;
	map_extras.row = row;
	map_extras.total = col * row;
	map_extras.scale = scale_calculator(map,
			map_extras.total);
	calculate_offset(map, &map_extras);
	open_window(&map_extras, map);
	return (0);
}
