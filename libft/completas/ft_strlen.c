/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:45:21 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/13 22:58:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *tab)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (tab[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}

/*#include <stdio.h>
int main()
{
   char tab[] = "";

   int result = ft_strlen(tab);
   printf("Longitud de la string %d", result);
   return 0;
   }*/
