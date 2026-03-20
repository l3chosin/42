#include "philo.h"
#include <stdlib.h>

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

t_table	save_basic_data(t_table sim, char **av)
{
	int	dummy;

	sim.n_philos = ft_atoi_ok(av[1], &dummy);
	sim.time_to_die = ft_atoi_ok(av[2], &dummy);
	sim.time_to_eat = ft_atoi_ok(av[3], &dummy);
	sim.time_to_sleep = ft_atoi_ok(av[4], &dummy);
	sim.time_to_think = ft_atoi_ok(av[5], &dummy);
	sim.must_eat = -1;
	return (sim);
}

t_table	prepare_emulation(char **av)
{
	t_table	simulation;
	int		dummy;
	int     i;

	simulation = save_basic_data(simulation, av);
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
	simulation.forks = malloc(sizeof(pthread_mutex_t) * simulation.n_philos);
	if (!simulation.forks)
	{
		free(simulation.philosopher);
		simulation.philosopher = NULL;
		return (simulation);
	}
	i = 0;
	while (i < simulation.n_philos)
	{
        simulation.philosopher[i].fork_left = &simulation.forks[i];
        simulation.philosopher[i].fork_right = &simulation.forks[(i + 1) % simulation.n_philos];
	}
	return (simulation);
}
