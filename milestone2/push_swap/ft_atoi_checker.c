/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:08:00 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/10 11:08:01 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	space_remover(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
}

static int	sign_assign(const char *str, int *i, int *sign, int *ok)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		if ((str[*i + 1] == '-' || str[*i + 1] == '+'))
			return (*ok = 0, 0);
		(*i)++;
	}
	return (1);
}

static int	int_validator(const char *str, long long result, int *i, int *ok)
{
	if (str[*i] != '\0')
		return (*ok = 0, 0);
	if (result < INT_MIN || INT_MAX < result)
		return (*ok = 0, 0);
	return (result);
}

int	ft_atoi_ok(const char *str,	int	*ok)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	*ok = 1;
	space_remover(str, &i);
	*ok = sign_assign(str, &i, &sign, ok);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (*ok = 0, 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	result = int_validator(str, result, &i, ok);
	return (result);
}
