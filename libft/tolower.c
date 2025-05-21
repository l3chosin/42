/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:02:43 by aluther           #+#    #+#             */
/*   Updated: 2025/05/20 22:02:45 by aluther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_tolower(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_isalpha(str[i]) != 0)
			{
				if (str[i] > 64 && str[i] < 91)
					str[i] += 32;
			}
		i++;
	}
}

/*#include<stdio.h>
int	main()
{
	char str[] = "HOLAMUNDO. . .   !2@#45^78'''s[[s'???";

	ft_tolower(str);
 	printf("Resultado: %s", str);
  return 0;
}*/
