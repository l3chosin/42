/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:44:50 by aluther-          #+#    #+#             */
/*   Updated: 2025/10/20 14:12:05 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	ok_handler(int sign)
{
	g_ack = sign;
}

static void	send_str(char *msg, int pid)
{
	int		i;
	int		j;
	int		bit;
	char	c;

	i = 0;
	while (1)
	{
		c = msg[i];
		j = 7;
		while (j >= 0)
		{
			g_ack = 0;
			bit = (c >> j) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_ack != SIGUSR2)
				pause();
			j--;
		}
		if (c == '\0')
		{
			while (g_ack != SIGUSR1)
				pause ();
			break ;
		}
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
		ft_printf("./client PID \"Your Message Here\"\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ok.sa_handler = ok_handler;
	sigemptyset(&ok.sa_mask);
	ok.sa_flags = 0;
	sigaction(SIGUSR2, &ok, NULL);
	sigaction(SIGUSR1, &ok, NULL);
	send_str(av[2], pid);
	return (0);
}
