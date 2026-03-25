/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:01:36 by aluther-          #+#    #+#             */
/*   Updated: 2026/01/16 16:01:38 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_table t_table;

typedef struct s_philo
{
	int	id;
	int	times_eaten;
	long    last_meal_time;
	pthread_t   philo_thread;
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;
	t_table *table;
}				t_philo;

typedef struct s_table
{
	int		n_philos;
	t_philo	*philosopher;
	pthread_mutex_t write_lock;
	pthread_mutex_t		*forks;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_think;
	int		time_to_sleep;
	int		must_eat;
}				t_table;

int		ft_atoi_ok(const char *str,	int	*ok);
void	philo_sleep(t_philo *philo);
void	pilo_think(int think_time);
void	philo_die(int death_time);

/* TEST FUNCTIONS */
void	print_test(t_table sim);

/*  PRE SIMULATION FUNCTIONS */
int	argument_validator(char **av);
void	save_basic_data(t_table *sim, char **av);
t_table	prepare_emulation(char **av);

/*  EMULATION */
void start_emulation(t_table sim);

#endif
