/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:05:28 by aluther-          #+#    #+#             */
/*   Updated: 2025/04/30 14:46:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>
int main()
{
	int a = 10;
	int b = 5;
	int div;
	int mod;
	
	ft_div_mod(a, b, &div, &mod);
	printf("Divisor %d\n", div);
	printf("residuo %d\n", mod);
	return 0;
}*/
