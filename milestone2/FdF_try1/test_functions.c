/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:37:14 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/14 09:37:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test_array(t_node *map_array, int column, int row)
{
	int	fila;
	int	col;
	int	i;

	if (!map_array)
		ft_printf("Error: el array no se ha creado.\n");
	ft_printf("Test del array de %d filas x %d columnas:\n", row, column);
	fila = 0;
	while (fila < row)
	{
		col = 0;
		while (col < column)
		{
			i = fila * column + col;
			ft_printf("Nodo [%d,%d]: x=%d, y=%d, z=%d, color=0x%X\n", fila, col,
				map_array[i].x,
				map_array[i].y,
				map_array[i].z,
				map_array[i].color);
			col++;
		}
		fila++;
	}
}
