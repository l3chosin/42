/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:14:30 by aluther-          #+#    #+#             */
/*   Updated: 2025/04/30 15:44:33 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	long	result;

	result = 1;
	i = 0;
	while (i < nb)
	{
		result *= (nb - i);
		i++;
	}
	return result;	
}

/*#include <stdio.h>
int	main()
{
	int	nb = 0;
	long r;

	r = ft_iterative_factorial(nb);
	printf("Resultado %ld", r);
	return 0;
}*/
