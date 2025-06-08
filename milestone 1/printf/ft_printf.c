/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:30:12 by aluther-          #+#    #+#             */
/*   Updated: 2025/06/08 11:30:14 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printspecifier(const char *format, va_list args, int i, int *len)
{
	if (format[i] == 'c')
		*len += ft_putchar((char)va_arg(args, int));
	if (format[i] == 's')
		*len += ft_putstr((char *)va_arg(args, char *));
	if (format[i] == 'p')
		*len += ft_ptrtohex((unsigned long)va_arg(args, void *));
	if (format[i] == 'd' || format[i] == 'i')
		*len += ft_putnbr((int)va_arg(args, int));
	if (format[i] == 'u')
		*len += ft_putpositivenbr((unsigned int)va_arg(args, unsigned int));
	if (format[i] == 'x')
		*len += ft_nbrtohex((unsigned long)va_arg(args, unsigned long));
	if (format[i] == 'X')
		*len += ft_uppernbrtohex((unsigned long)va_arg(args, unsigned long));
	if (format[i] == '%')
		*len += ft_putchar('%');
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_printspecifier(format, args, i, &len);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h>

int main()
{
    int len1, len2;

    // Prueba con un string
    len1 = ft_printf("Mi printf: %s\n", "Hola mundo");
    len2 = printf("EL printf: %s\n", "Hola mundo");
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Prueba con un carácter
    len1 = ft_printf("Mi printf: %c\n", 'A');
    len2 = printf("EL printf: %c\n", 'A');
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Prueba con un entero
    len1 = ft_printf("Mi printf: %d\n", 42);
    len2 = printf("EL printf: %d\n", 42);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Prueba con un número sin signo
    len1 = ft_printf("Mi printf: %u\n", 42000);
    len2 = printf("EL printf: %u\n", 42000);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Prueba con punteros
    void *ptr = (void *)0x12345678;
    len1 = ft_printf("Mi printf: %p\n", ptr);
    len2 = printf("EL printf: %p\n", ptr);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Prueba con hexadecimal minúscula
    len1 = ft_printf("Mi printf: %x\n", 255);
    len2 = printf("EL printf: %x\n", 255);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Prueba con hexadecimal mayúscula
    len1 = ft_printf("Mi printf: %X\n", 255);
    len2 = printf("EL printf: %X\n", 255);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    return 0;
}*/
