/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:51:28 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 20:57:31 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	philo_sleep(t_philo *philo)
{
	printf("%lld %i is sleeping\n", get_timestamp_ms(), philo->id);
	smart_sleep(philo->table->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	philo->last_meal_time = get_timestamp_ms();
	smart_sleep(philo->table->time_to_eat);
	philo->times_eaten += 1;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void	philo_think(t_philo *philo)
{
	printf("%lld %i is thinking\n", get_timestamp_ms(), philo->id);
	smart_sleep(philo->table->time_to_think);
	printf("%lld %i stopped thinking\n", get_timestamp_ms(), philo->id);
}
