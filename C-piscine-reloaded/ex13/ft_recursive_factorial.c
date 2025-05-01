/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:55:29 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/01 13:30:41 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	
	return (nb * ft_recursive_factorial(nb - 1));
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
