/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:49:21 by aluther-          #+#    #+#             */
/*   Updated: 2025/10/20 10:35:19 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

static pid_t	g_active_client = 0;

static int	bit_selector(int signal)
{
	if (signal == SIGUSR1)
	{
		return (0);
	}
	else if (signal == SIGUSR2)
	{
		return (1);
	}
	return (-1);
}

static void	do_things(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	int			bit;
	pid_t		client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (g_active_client == 0)
		g_active_client = client_pid;
	if (client_pid != g_active_client)
		return ;
	bit = bit_selector(signal);
	if (bit == -1)
		return ;
	c = (c << 1) | bit;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		kill(client_pid, SIGUSR2);
		if (c == '\0')
		{
			kill(client_pid, SIGUSR1);
			g_active_client = 0;
			write(1, "\n", 1);
			c = 0;
			i = 0;
			return ;
		}
		c = 0;
		i = 0;
		return ;
	}
	kill(client_pid, SIGUSR2);
}


int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	sa.sa_sigaction = do_things;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
