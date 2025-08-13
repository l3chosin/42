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
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		column;
	int		row;
	t_node	*map_array;
	int		fd;

	read_map(argc, argv, &column, &row);
	map_array = array_creator(column, row);
	fd = open(argv[1], O_RDONLY);
	map_data_assign(fd, map_array, column, row);
	test_array(map_array, column, row);
	free(map_array);
	return (0);
}
