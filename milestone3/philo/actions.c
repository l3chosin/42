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

void	philo_eat(int eat_time)
{
	usleep(eat_time * 1000);
}

void	pilo_think(int think_time)
{
	usleep(think_time * 1000);
}

void	philo_die(int death_time)
{
	usleep(death_time * 1000);
}
