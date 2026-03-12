/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:47:17 by aluther-          #+#    #+#             */
/*   Updated: 2026/01/16 14:47:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

int	argument_validator(char **av)
{
	int	i;
	int	ok;
	int	n;

	i = 1;
	ok = 0;
	while (av[i])
	{
		n = ft_atoi_ok(av[i], &ok);
		if (ok == 0)
			return (-1);
		if (n < 0)
			return (-1);
		else
			i++;
	}
	return (0);
}

t_table	prepare_emulation(char **av)
{
	t_table	simulation;
	int		dummy;

	simulation.n_philos = ft_atoi_ok(av[1], &dummy);
	simulation.time_to_die = ft_atoi_ok(av[2], &dummy);
	simulation.time_to_eat = ft_atoi_ok(av[3], &dummy);
	simulation.time_to_sleep = ft_atoi_ok(av[4], &dummy);
	simulation.time_to_think = ft_atoi_ok(av[5], &dummy);
	simulation.must_eat = -1;
	if (av[6])
		simulation.must_eat = ft_atoi_ok(av[6], &dummy);
	simulation.philosopher = malloc((sizeof(t_philo)
				* simulation.n_philos));
	if (!simulation.philosopher)
	{
		simulation.philosopher = NULL;
		simulation.forks = NULL;
		return (simulation);

	}
	simulation.forks = malloc(sizeof(int) * simulation.n_philos);
	if (!simulation.forks)
	{
		free(simulation.philosopher);
		simulation.philosopher = NULL;
		return (simulation);
	}
	return (simulation);
}

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

void	cleanup(t_table *table)
{
	free(table->philosopher);
	free(table->forks);
	table->philosopher = NULL;
	table->forks = NULL;
}

int	main(int ac, char **av)
{
	t_table	sim;

	if (ac == 6 || ac == 7)
	{
		if (argument_validator(av) == -1)
			return (printf("Error en los argumentos\n"), 0);
		else
		{
			sim = prepare_emulation(av);
			if (!sim.philosopher || !sim.forks)
				return (free(sim.philosopher), free(sim.forks), 1);
			print_test(sim);
			cleanup(&sim);
		}
	}
	else
		printf("Faltan datos o hay demasiados\n");
}
