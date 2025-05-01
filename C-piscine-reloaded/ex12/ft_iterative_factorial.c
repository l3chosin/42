/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:14:30 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/01 13:23:44 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	long long	result;

	result = 1;
	i = 1;
	if (nb < 0)
		result = 0;
	if (nb == 0)
		result = 1;
	while (i < nb)
	{
		result *= i;
		i++;
	}
	return (result);
}

#include <stdio.h>
int	main()
{
	int	nb = 12;
	long r;

	r = ft_iterative_factorial(nb);
	printf("Resultado %ld", r);
	return 0;
}
