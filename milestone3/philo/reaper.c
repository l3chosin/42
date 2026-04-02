/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 23:47:05 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 23:47:34 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <unistd.h>

void	check_win(t_table *sim)
{
	int	i;
	int	trigger;

	if (sim->must_eat == -1)
		return ;
	i = 0;
	trigger = 1;
	while (i < sim->n_philos)
	{
		pthread_mutex_lock(&sim->meal_lock);
		if (sim->philosopher[i].times_eaten < sim->must_eat)
			trigger = 0;
		pthread_mutex_unlock(&sim->meal_lock);
		i++;
	}
	if (trigger == 1)
	{
		pthread_mutex_lock(&sim->stop_lock);
		sim->sim_stop = 1;
		pthread_mutex_unlock(&sim->stop_lock);
	}
}

void	check_death(t_table *sim)
{
	int			i;
	long long	time_since_last_meal;

	i = 0;
	while (i < sim->n_philos)
	{
		pthread_mutex_lock(&sim->meal_lock);
		time_since_last_meal = get_timestamp_ms()
			- sim->philosopher[i].last_meal_time;
		pthread_mutex_unlock(&sim->meal_lock);
		if (time_since_last_meal >= sim->time_to_die)
		{
			pthread_mutex_lock(&sim->stop_lock);
			sim->sim_stop = 1;
			pthread_mutex_unlock(&sim->stop_lock);
			print_action(&sim->philosopher[i], "died");
			return ;
		}
		i++;
	}
}

void	*reaper_routine(void *arg)
{
	t_table	*sim;

	sim = (t_table *)arg;
	while (!check_sim_stop(sim))
	{
		check_death(sim);
		check_win(sim);
		usleep(500);
	}
	return (NULL);
}
