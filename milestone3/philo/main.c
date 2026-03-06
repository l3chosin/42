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

t_sim	prepare_emulation(char **av)
{
	t_sim	simulation;
	int		dummy;

	simulation.table.n_philos = ft_atoi_ok(av[1], &dummy);
	simulation.forks = ft_atoi_ok(av[1], &dummy);
	simulation.time_to_die = ft_atoi_ok(av[2], &dummy);
	simulation.time_to_eat = ft_atoi_ok(av[3], &dummy);
	simulation.time_to_sleep = ft_atoi_ok(av[4], &dummy);
	simulation.time_to_think = ft_atoi_ok(av[5], &dummy);
	simulation.must_eat = -1;
	if (av[6])
		simulation.must_eat = ft_atoi_ok(av[6], &dummy);
	simulation.table.philosopher = malloc((sizeof(t_philo)
				* simulation.table.n_philos));
	return (simulation);
}

void	print_test(t_sim sim, char **av)
{
	printf("Forks = %i\n", sim.forks);
	printf("N of philosophers = %i\n", sim.table.n_philos);
	printf("Time to die = %i\n", sim.time_to_die);
	printf("Time to eat = %i\n", sim.time_to_eat);
	printf("Time to sleep = %i\n", sim.time_to_sleep);
	printf("Time to think = %i\n", sim.time_to_think);
	if (av[6])
		printf("Times philo must eat = %i\n", sim.must_eat);
}

int	main(int ac, char **av)
{
	t_sim	sim;

	if (ac == 6 || ac == 7)
	{
		if (argument_validator(av) == -1)
			return (printf("Error en los argumentos\n"), 0);
		else
		{
			sim = prepare_emulation(av);
			print_test(sim, av);
		}
	}
	else
		printf("Datos incorrectos >:(\n");
}
