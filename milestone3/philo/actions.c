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
#include <unistd.h>

void	philo_sleep(int sleep_time)
{
	usleep(sleep_time * 1000);
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
