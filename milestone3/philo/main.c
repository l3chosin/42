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

#include <stdio.h>
#include "philo.h"

int	argument_validator(char **av)
{
	int	i;
	int	ok;

	i = 1;
	ok = 0;
	while (av[i])
	{
		ft_atoi_ok(av[i], &ok);
		if (ok == 0)
			return (-1);
		else
			i++;
	}
	return (0);
}

int	prepare_emulation(char **av)
{
	t_sim	simulation;
	int		dummy;

	simulation.table.n_philos = ft_atoi_ok(av[1], &dummy);
	simulation.forks = ft_atoi_ok(av[1], &dummy);
	simulation.time_to_eat = ft_atoi_ok(av[2], &dummy);
	simulation.time_to_think = ft_atoi_ok(av[3], &dummy);
	simulation.time_to_die = ft_atoi_ok(av[4], &dummy);
	if (av[6])
	{

	}
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (argument_validator(av) == -1)
		{
			printf("Error en los argumentos\n");
			return (0);
		}
		else
		{
			prepare_emulation(av);
		}
	}
	else
		printf("Faltan datos >:(\n");
}
