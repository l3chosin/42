/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:47:17 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 23:47:30 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->stop_lock);
	pthread_mutex_destroy(&table->write_lock);
	free(table->philosopher);
	free(table->forks);
	table->philosopher = NULL;
	table->forks = NULL;
}

int	main(int ac, char **av)
{
	t_table	sim;

	if (ac == 5 || ac == 6)
	{
		if (argument_validator(av) == -1)
			return (printf("Error en los argumentos\n"), 0);
		prepare_emulation(&sim, av);
		if (!sim.philosopher || !sim.forks)
			return (1);
		if (sim.n_philos == 0 || sim.time_to_die == 0
			|| sim.time_to_eat == 0 || sim.time_to_sleep == 0
			|| sim.must_eat == 0)
			return (cleanup(&sim), 0);
		start_emulation(&sim);
		cleanup(&sim);
	}
	else
		printf("Faltan o sobran argumentos \n");
	return (0);
}
