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
	int		col;
	int		row;

	col = 0;
	row = read_map_create_array(argc, argv, &map, &col);
	if (col == 0)
		return (ft_printf("This shit ain't good\n"), 1);
	ft_printf("Columnas: %d \nFilas: %d\n", col, row);
	open_window(1920, 1080);
	return (0);
}
