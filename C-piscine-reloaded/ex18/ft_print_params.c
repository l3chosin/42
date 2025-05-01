/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:31:32 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/01 18:45:58 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	ft_putchar(char c);

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc > 0)
	{
		j = 1;
		while (j < argc)
		{
			i = 0;
			while (argv[j][i] != '\0')
			{
				ft_putchar(argv[j][i]);
				i++;
			}
			ft_putchar('\n');
			j++;
		}
	}
	return (0);
}
