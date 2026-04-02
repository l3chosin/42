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
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i is sleeping\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
	usleep(philo->table->time_to_sleep * 1000);
    pthread_mutex_lock(&philo->table->write_lock);
	printf("%lld %i has woken up\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
}

void	philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->fork_left);
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i has taken the left fork\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
    pthread_mutex_lock(philo->fork_right);
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i has taken the right fork\n", get_timestamp_ms(), philo->id);
    printf("%lld %i is eating\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
    usleep(philo->table->time_to_eat * 1000);
    philo->times_eaten += 1;
    philo->last_meal_time = get_timestamp_ms();
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i finished eating\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
    pthread_mutex_unlock(philo->fork_right);
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i has released the right fork\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
    pthread_mutex_unlock(philo->fork_left);
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i has released the left fork\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
}

void	philo_think(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->write_lock);
    printf("%lld %i is thinking\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
	usleep(philo->table->time_to_think * 1000);
    pthread_mutex_lock(&philo->table->write_lock);
	printf("%lld %i stopped thinking\n", get_timestamp_ms(), philo->id);
    pthread_mutex_unlock(&philo->table->write_lock);
}
