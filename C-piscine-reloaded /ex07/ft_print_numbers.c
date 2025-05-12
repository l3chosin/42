/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:36:17 by aluther-          #+#    #+#             */
/*   Updated: 2025/04/29 20:36:42 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_putchar((i + '0'));
		i++;
	}
}

/*int main(void)
{
	ft_print_numbers();
	return 0;
}*/
