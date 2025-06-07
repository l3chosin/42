/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:27:40 by aluther-          #+#    #+#             */
/*   Updated: 2025/06/07 10:27:42 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_hexlen(unsigned long ptr)
{
	int	l;

	l = 1;
	while (ptr >= 16)
	{
		ptr /= 16;
		l++;
	}
	return (l + 2);
}

char	*ft_nbrtohex(unsigned long p)
{
	char	*hex;
	char	*final;
	int		j;
	int		len;

	hex = "0123456789abcdef";
	len = ft_hexlen(p);
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	final[0] = '0';
	final [1] = 'x';
	final[len] = '\0';
	while (len > 2)
	{
		len--;
		j = p % 16;
		p /= 16;
		final[len] = hex[j];
	}
	return (final);
}

/*#include <stdio.h>

int main()
{
    char *res;

    res = ft_nbrtohex(25000);
    printf("Resultado: %s", res);
    return 0;
    }*/
