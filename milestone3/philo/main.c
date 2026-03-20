/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:47:17 by aluther-          #+#    #+#             */
/*   Updated: 2026/01/16 14:47:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void	cleanup(t_table *table)
{
	free(table->philosopher);
	free(table->forks);
	table->philosopher = NULL;
	table->forks = NULL;
}

int	main(int ac, char **av)
{
	t_table	sim;

	if (ac == 6 || ac == 7)
	{
		if (argument_validator(av) == -1)
			return (printf("Error en los argumentos\n"), 0);
		else
		{
			sim = prepare_emulation(av);
			if (!sim.philosopher || !sim.forks)
				return (free(sim.philosopher), free(sim.forks), 1);
			print_test(sim);
			start_emulation(sim);
			cleanup(&sim);
		}
	}
	else
		printf("Faltan datos o hay demasiados\n");
}
