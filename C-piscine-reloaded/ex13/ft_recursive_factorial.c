/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:55:29 by aluther-          #+#    #+#             */
/*   Updated: 2025/04/30 16:46:39 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb == 0)
		result = 1;
	if (nb < 0)
		result = 0;
	result = nb;
	if (nb - 1 > 0)
		result *= ft_recursive_factorial(nb - 1);
	return (result);
}

/*#include <stdio.h>
int	main()
{
	int nb = 7;
	int r;
	
	r = ft_recursive_factorial(nb);
	printf("Resultado %d", r);
	return (0);	
}*/
