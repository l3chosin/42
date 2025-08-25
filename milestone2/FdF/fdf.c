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
	t_node	*map;
	int		col;
	int		row;

	col = 0;
	row = read_map_create_array(argc, argv, &map, &col);
	ft_printf("Valor de col %d \n Valor de row %d\n", col, row);
	return (0);
}
