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

typedef struct s_philo
{
	int	id;
	int	times_eaten;

}				t_philo;

typedef struct s_table
{
	int		n_philos;
	t_philo	*philosopher;
	int		*forks;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_think;
	int		time_to_sleep;
	int		must_eat;
}				t_table;

int		ft_atoi_ok(const char *str,	int	*ok);
void	philo_sleep(int sleep_time);
void	philo_eat(int eat_time);
void	pilo_think(int think_time);
void	philo_die(int death_time);
#endif
