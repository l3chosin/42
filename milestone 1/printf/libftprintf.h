/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:18:00 by aluther-          #+#    #+#             */
/*   Updated: 2025/06/07 10:18:02 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putnbr(long n);
int		ft_putpositivenbr(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_ptrtohex(unsigned long p);
int		ft_nbrtohex(unsigned long p);
int		ft_uppernbrtohex(unsigned long p);
int		ft_hexlen(unsigned long ptr);
char	*ft_strtoupper(char *str);
int	ft_printf(char const *format, ...);
#endif
