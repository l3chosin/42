/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_emulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:46:53 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 20:53:46 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	save_basic_data(t_table *sim, char **av)
{
	int	dummy;

	sim->n_philos = ft_atoi_ok(av[1], &dummy);
	sim->time_to_die = ft_atoi_ok(av[2], &dummy);
	sim->time_to_eat = ft_atoi_ok(av[3], &dummy);
	sim->time_to_sleep = ft_atoi_ok(av[4], &dummy);
	sim->time_to_think = ft_atoi_ok(av[5], &dummy);
	sim->must_eat = -1;
}

void    save_arrays(t_table *sim, char **av)
{
    int dummy;

   	if (av[6])
		sim->must_eat = ft_atoi_ok(av[6], &dummy);
	sim->philosopher = malloc((sizeof(t_philo)
				* sim->n_philos));
	if (!sim->philosopher)
	{
		sim->philosopher = NULL;
		sim->forks = NULL;
	}
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->n_philos);
	if (!sim->forks)
	{
		free(sim->philosopher);
		sim->philosopher = NULL;
	}
}

void    init_mutex(t_table *sim)
{
    int i;

   	i = 0;
	while (i < sim->n_philos)
	{
	    pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
}

void    init_extra_data(t_table *sim)
{
    int i;

    i = 0;
   	while (i < sim->n_philos)
	{
	       sim->philosopher[i].table = sim;
           sim->philosopher[i].fork_left = &sim->forks[i];
           sim->philosopher[i].fork_right = &sim->forks[(i + 1) % sim->n_philos];
           sim->philosopher[i].id = i + 1;
           sim->philosopher[i].times_eaten = 0;
           i++;
	}
}

t_table	prepare_emulation(char **av)
{
	t_table	simulation;

	save_basic_data(&simulation, av);
	save_arrays(&simulation, av);
	init_mutex(&simulation);
	init_extra_data(&simulation);

	return (simulation);
}
