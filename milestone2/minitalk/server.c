/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:49:21 by aluther-          #+#    #+#             */
/*   Updated: 2025/10/09 15:49:23 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

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

static void	do_things(int signal)
{
	static char	c = 0;
	static int	i = 0;
	int			bit;

	bit = bit_selector(signal);
	if (bit == -1)
	{
		write(1, "La comunicacion ha fallado", 27);
		return ;
	}
	c = (c << 1) | bit;
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_handler = do_things;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
