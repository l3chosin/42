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

#include "libftprintf.h"

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

int	ft_ptrtohex(unsigned long p)
{
	char	*hex;
	char	*final;
	int		j;
	int		len;
	int		og_len;

	hex = "0123456789abcdef";
	if (p == 0)
		return (ft_putstr("(nil)"));
	len = ft_hexlen(p) + 2;
	og_len = len;
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (0);
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
	ft_putstr(final);
	free(final);
	return (og_len);
}

int	ft_uppernbrtohex(unsigned long p)
{
	char	*hex;
	char	*final;
	int		j;
	int		len;
	int		og_len;

	hex = "0123456789abcdef";
	len = ft_hexlen(p);
	og_len = len;
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (0);
	final[len] = '\0';
	while (len > 0)
	{
		len--;
		j = p % 16;
		p /= 16;
		final[len] = hex[j];
	}
	ft_strtoupper(final);
	ft_putstr(final);
	free(final);
	return (og_len);
}

int	ft_nbrtohex(unsigned long p)
{
	char	*hex;
	char	*final;
	int		j;
	int		len;
	int		og_len;

	hex = "0123456789abcdef";
	len = ft_hexlen(p);
	og_len = len;
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (0);
	final[len] = '\0';
	while (len > 0)
	{
		len--;
		j = p % 16;
		p /= 16;
		final[len] = hex[j];
	}
	ft_putstr(final);
	free(final);
	return (og_len);
}
