/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:20:24 by aluther-          #+#    #+#             */
/*   Updated: 2026/04/02 23:47:37 by aluther-         ###   ########.fr       */
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
	if (sim.must_eat >= 0)
		printf("Times philo must eat = %i\n", sim.must_eat);
}
