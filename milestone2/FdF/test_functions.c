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
	if (!map_array)
	{
		printf("Error: el array no se ha creado.\n");
		return ;
	}
	printf("Test del array de %d filas x %d columnas:\n", row, column);
	for (int fila = 0; fila < row; fila++)
	{
		for (int col = 0; col < column; col++)
		{
			int i = fila * column + col;
			printf("Nodo [%d,%d]: x=%d, y=%d, z=%d, color=0x%X\n",
				fila, col,
				map_array[i].x,
				map_array[i].y,
				map_array[i].z,
				map_array[i].color);
		}
	}
}

int	column_row_tester(int argc, char *argv[])
{
	int	column;
	int	row;
	int	result;

	ft_printf("=== Probador de lectura de mapas ===\n");
	result = read_map(argc, argv, &column, &row);
	if (result == -1)
	{
		ft_printf("Error al leer el mapa.\n");
		return (1);
	}
	ft_printf("\n=== Resultados ===\n");
	ft_printf("Columnas: %d\n", column);
	ft_printf("Filas: %d\n", row);
	ft_printf("Total de elementos: %d\n", column * row);
	return (0);
}
