/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:21:27 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 23:47:27 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		smart_sleep(philo->table->time_to_sleep / 2, philo->table);
	while (check_sim_stop(philo->table) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	start_emulation(t_table *sim)
{
	int	i;

	i = 0;
	while (i < sim->n_philos)
	{
		pthread_create(&sim->philosopher[i].philo_thread, NULL, philo_routine,
			&sim->philosopher[i]);
		i++;
	}
	pthread_create(&sim->reaper, NULL, reaper_routine, sim);
	i = 0;
	while (i < sim->n_philos)
	{
		pthread_join(sim->philosopher[i].philo_thread, NULL);
		i++;
	}
	pthread_join(sim->reaper, NULL);
}
