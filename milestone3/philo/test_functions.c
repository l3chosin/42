/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:20:24 by aluther-          #+#    #+#             */
/*   Updated: 2026/03/12 20:20:25 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_test(t_table sim)
{
	printf("Forks = %i\n", sim.n_philos);
	printf("N of philosophers = %i\n", sim.n_philos);
	printf("Time to die = %i\n", sim.time_to_die);
	printf("Time to eat = %i\n", sim.time_to_eat);
	printf("Time to sleep = %i\n", sim.time_to_sleep);
	printf("Time to think = %i\n", sim.time_to_think);
	if (sim.must_eat >= 0)
		printf("Times philo must eat = %i\n", sim.must_eat);
}
