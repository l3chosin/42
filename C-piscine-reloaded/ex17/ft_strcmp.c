/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:06:33 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/01 15:36:28 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
			return (s1 - s2);
	}
	return (0);
}

/*#include <stdio.h>
int     main()
{
        char s1[] = "a";
        char s2[] = "Hola";
        int result = ft_strcmp(s1, s2);
        printf("Resultado %d", result);
        return 0;
}*/
