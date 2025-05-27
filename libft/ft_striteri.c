/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:14:16 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/27 20:14:17 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>

void    to_lower(unsigned int i, char *c)
{
    (void)i; // Ignoramos el índice porque no es necesario aquí
    *c = ft_tolower(*c); // Aplicamos ft_tolower al contenido de c
}

int main(void)
{
    char str[] = "HELLO WORLD";

    printf("Antes de ft_striteri: %s\n", str);
    ft_striteri(str, to_lower);
    printf("Después de ft_striteri: %s\n", str);

    return 0;
    }*/
