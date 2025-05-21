/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:55:20 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 15:09:44 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(char *str, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		str[i] = '\0';
		i++;
	}
}

/*#include<stdio.h>
int main()
{
    char str[] = "Hola gordiiiiii";
    int c = 5;
    printf("Cadena original: %s\n", str);
    ft_bzero(str, c);
    printf("Cadena tras borrado: %s\n", str);
    return 0;
    }*/
