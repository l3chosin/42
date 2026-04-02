/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:47:17 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 20:46:47 by aluther-         ###   ########.fr       */
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

		prepare_emulation(&sim, av);
		if (!sim.philosopher || !sim.forks)
			return (1);
		printf("DEBUG: Eat: %d, Die: %d, Sleep: %d\n", sim.time_to_eat, sim.time_to_die, sim.time_to_sleep);
		start_emulation(&sim);
		cleanup(&sim);
	}
	return (0);
}
