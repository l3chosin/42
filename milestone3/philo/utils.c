/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:02:42 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 20:49:02 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/types/struct_timeval.h>

int	argument_validator(char **av)
{
	int	i;
	int	ok;
	int	n;

	i = 1;
	while (av[i])
	{
		ok = 0;
		n = ft_atoi_ok(av[i], &ok);
		if (ok == 0 || n < 0)
			return (-1);
		if (n < 0)
			return (-1);
		else
			i++;
	}
	return (0);
}

long long	get_timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	smart_sleep(int time_in_ms, t_table *table)
{
	long long	start_time;

	start_time = get_timestamp_ms();
	while ((get_timestamp_ms() - start_time) < (long long)time_in_ms)
	{
		if (check_sim_stop(table) == 1)
			break ;
		usleep(500);
	}
}

void	print_action(t_philo *philo, char *msg)
{
	long long	current_time;
	long long	time_passed;

	pthread_mutex_lock(&philo->table->write_lock);
	current_time = get_timestamp_ms();
	time_passed = current_time - philo->table->start_time;
	if (check_sim_stop(philo->table) == 0 || msg[0] == 'd')
		printf("%lld %i %s\n", time_passed, philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_lock);
}

int	check_sim_stop(t_table *sim)
{
	int	stop_flag;

	pthread_mutex_lock(&sim->stop_lock);
	stop_flag = sim->sim_stop;
	pthread_mutex_unlock(&sim->stop_lock);
	return (stop_flag);
}
