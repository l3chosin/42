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
	return (l);
}

char	*ft_nbrtohex(unsigned long p)
{
	char	*hex;
	char	*final;
	int		j;
	int		len;

	hex = "0123456789ABCDEF";
	len = ft_hexlen(p);
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	final[len] = '\0';
	while (len > 0)
	{
		len--;
		j = p % 16;
		p /= 16;
		final[len] = hex[j];
	}
	return (final);
}
