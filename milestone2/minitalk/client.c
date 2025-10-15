/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:44:50 by aluther-          #+#    #+#             */
/*   Updated: 2025/10/14 12:06:09 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ok_handler(int sign)
{
	(void)sign;
}

static void	send_str(char *msg, int pid)
{
	int		i;
	int		j;
	int		bit;
	char	c;
	char	*tmp;

	i = 0;
	while (1)
	{
		tmp = msg;
		c = tmp[i];
		j = 7;
		while (j >= 0)
		{
			bit = (tmp[i] >> j) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			usleep(5000);
			j--;
		}
		if (c == '\0')
			break ;
		i++;
	}
}

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	ok;

	if (ac != 3)
	{
		ft_printf("Error! Use the client as following\n");
		ft_printf("./client PID \"YourMessageHere\"\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ok.sa_handler = ok_handler;
	sigemptyset(&ok.sa_mask);
	ok.sa_flags = 0;
	sigaction(SIGUSR2, &ok, NULL);
	send_str(av[2], pid);
	return (0);
}
