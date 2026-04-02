/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:21:27 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 20:46:43 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->table->write_lock);
	printf("%lld %i has born\n", get_timestamp_ms(), philo->id);
	pthread_mutex_unlock(&philo->table->write_lock);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/* void *reaper_routine(void *arg)
{
    t_table *sim;

    sim = (t_table *)arg;
    Tengo que hacer la rutina del reaper que comprueba si algun filosofo se ha muerto.
     * Para ello necesito que los filosofos impriman el momento en el que han comido por
     * ultima vez y así poder hacer la resta. Si la resta es más grande que el tiempo de
     * muerte, entonces el reaper ha de cambiar una variable de encendido en la table que hará
     * que se pare la simulacion cuando alguien muere. He de hacer que los filosofos comprueben en cada
     * acción este swithc. Y también he de hacer que el usleep lo haga, por lo que deberia hacer
     * uno custom que cada poco compruebe el estado de la variable en la simulacion.      */
//}


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
	//pthread_create(&sim.reaper, NULL, reaper_routine, &sim);
	i = 0;
	while (i < sim->n_philos)
	{
		pthread_join(sim->philosopher[i].philo_thread, NULL);
		i++;
	}
	//pthread_join(sim.reaper, NULL);
}
