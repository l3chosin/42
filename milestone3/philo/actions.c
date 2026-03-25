/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:51:28 by aluther-          #+#    #+#             */
/*   Updated: 2026/03/06 21:51:30 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	philo_sleep(t_philo *philo)
{
    printf("Filosofo %i se acuesta a dormir\n", philo->id);
	usleep(philo->table->time_to_sleep * 1000);
	printf("Filosofo %i se ha despertado\n", philo->id);
}

void	philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->fork_left);
    printf("Filosofo %i ha cogido el tenedor de su izquierda\n", philo->id);
    pthread_mutex_lock(philo->fork_right);
    printf("Filosofo %i ha cogido el tenedor de su derecha\n", philo->id);
    usleep(philo->table->time_to_eat * 1000);
    philo->times_eaten += 1;
    printf("Filosofo %i ha acabado de comer\n", philo->id);
    pthread_mutex_unlock(philo->fork_right);
    printf("Filosofo %i ha soltado el tenedor de su derecha\n", philo->id);
    pthread_mutex_unlock(philo->fork_left);
    printf("Filosofo %i ha soltado el tenedor de su izquierda\n", philo->id);
}

void	philo_think(t_philo *philo)
{
    printf("Filosofo %i empeza a pensar \n", philo->id);
	usleep(philo->table->time_to_think * 1000);
    printf("Filosofo %i ha acabado de pensar \n", philo->id);

}

void	philo_die(int death_time)
{
	usleep(death_time * 1000);
}
