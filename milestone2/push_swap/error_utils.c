/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:50 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 13:28:13 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_printf("Error! Utiliza el programa con:\n");
		ft_printf("./push_swap numero1 numero2 numero3 numero4 ...\n");
	}
	if (error == 2)
	{
		ft_printf("Se ha encontrado un argumento invalido en la posicion\n");
	}
	if (error == 3)
		ft_printf("Hay argumentos duplicados :''(\n");
	if (error == 4)
		ft_printf("Liberando la memoria del stack\n");
}
