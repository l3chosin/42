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

void	smart_sleep(int time_in_ms)
{
	long long	start_time;

	start_time = get_timestamp_ms();
	while ((get_timestamp_ms() - start_time) < (long long)time_in_ms)
		usleep(500);
}

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->write_lock);
	printf("%lld %i %s\n", get_timestamp_ms(), philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_lock);
}
