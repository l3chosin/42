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
	int	n_philo;
	int	times_eaten;

}				t_philo;

typedef struct s_table
{
	t_philo	philosopher;
	t_philo	*l_philo;
	t_philo	*r_philo;
}				t_table;

typedef struct s_sim
{
	int	forks;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_think;
	int	must_eat;
}				t_sim;



#endif
