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
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int	column;
	int	row;
	int result;

	ft_printf("=== Probador de lectura de mapas ===\n");
	result = read_map(argc, argv, &column, &row);
	if (result == -1)
	{
		ft_printf("Error al leer el mapa.\n");
		return(1);
	}
	printf("\n=== Resultados ===\n");
    printf("Columnas: %d\n", column);
    printf("Filas: %d\n", row);
    printf("Total de elementos: %d\n", column * row);
    return (0);
}
