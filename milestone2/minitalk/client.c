/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:44:50 by aluther-          #+#    #+#             */
/*   Updated: 2025/10/09 15:45:45 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_str(char *av[], int pid)
{
	int		i;
	int		j;
	int		bit;
	char	c;

	i = 0;
	while (av[1][i] != '\0')
	{
		c = av[1][i];
		j = 0;
		while (j <= 7)
		{
			bit = (c >> j) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Error! Use the client as following\n");
		ft_printf("./client PID \"YourMessageHere\"\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	send_str(av, pid);
	return (0);
}
