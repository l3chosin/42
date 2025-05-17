/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:07:25 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/17 19:00:01 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		result += s1[i] - s2[i];
		i++;
	}
	return (result);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	char s1[] = "HolA!";
	char s2[] = "jshlB?";
	int n = 3;
	int final_result;
	int ref;

	final_result = ft_strncmp(s1,	s2, n);
	ref = strncmp(s1, s2, n);
	if (final_result == 0)
		printf("Los primeros %d caracteres de las dos str son iguales.
	       	Valor retornado %d. 
		Valor de comparacion con strlcmp %d\n", n, final_result, ref);
	if(final_result > 0)
		printf("Los primeros %d carateres de las dos funciones son diferentes. 
		Valor retornado %d. 
		Valor de comparacion con strlcmp %d\n", n, final_result, ref);
	if(final_result < 0)
		printf("Los primeros %d caracteres de las dos funciones son diferentes. 
		Valor retornado %d. 
		Valor de comparacion con strlcmp %d\n", n, final_result, ref);
	return (0);
}*/
