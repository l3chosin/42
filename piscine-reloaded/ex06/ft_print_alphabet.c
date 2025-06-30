/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:26:11 by aluther-          #+#    #+#             */
/*   Updated: 2025/04/29 20:28:37 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		ft_putchar(('a' + i));
		i++;
	}
}

/*int main(void)
{
	ft_print_alphabet();
	return 0;
}*/
