/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:51:28 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 23:47:26 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	smart_sleep(philo->table->time_to_sleep, philo->table);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, "has taken a fork");
	if (philo->table->n_philos == 1)
	{
		smart_sleep(philo->table->time_to_die, philo->table);
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal_time = get_timestamp_ms();
	pthread_mutex_unlock(&philo->table->meal_lock);
	smart_sleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->times_eaten += 1;
	pthread_mutex_unlock(&philo->table->meal_lock);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void	philo_think(t_philo *philo)
{
	if (check_sim_stop(philo->table) == 1)
		return ;
	print_action(philo, "is thinking");
	if (philo->table->n_philos % 2 != 0)
		smart_sleep(philo->table->time_to_eat / 2, philo->table);
}
