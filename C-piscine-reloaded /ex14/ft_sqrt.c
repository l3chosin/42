/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:01:17 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/01 14:11:30 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	while (nb > 0 && i < (nb / 2))
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int	main()
{
	int nb = 25;
	int result;

	result = ft_sqrt(nb);
	printf("Resultado %d", result);
	return (0);
}*/
