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

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

int	ft_putnbr(long n);
int	ft_putpositivenbr(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
