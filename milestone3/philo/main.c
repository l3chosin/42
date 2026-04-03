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
	if (table->forks)
	{
		while (i < table->n_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->stop_lock);
	pthread_mutex_destroy(&table->write_lock);
	if (table->philosopher)
	{
		free(table->philosopher);
		table->philosopher = NULL;
	}
}

int	main(int ac, char **av)
{
	t_table	sim;

	if (ac == 5 || ac == 6)
	{
		if (argument_validator(av) == -1)
			return (printf("Error en los argumentos\n"), 1);
		if (prepare_emulation(&sim, av) == 1)
			return (1);
		if (sim.n_philos == 0 || sim.time_to_die == 0
			|| sim.time_to_eat == 0 || sim.time_to_sleep == 0
			|| sim.must_eat == 0)
		{
			cleanup(&sim);
			return (0);
		}
		start_emulation(&sim);
		cleanup(&sim);
	}
	else
		return (printf("Faltan o sobran argumentos \n"), 1);
	return (0);
}
