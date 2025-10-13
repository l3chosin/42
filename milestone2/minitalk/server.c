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

#include "libft/libft.h"
#include "minitalk.h"
#include <signal.h>

void	handler1(int sign)
{
	(void)sign;

	ft_printf("0\n");
}

void	handler2(int sign)
{
	(void)sign;

	ft_printf("1\n");
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					pid;


	pid = getpid();
	sa1.sa_handler = handler1;
	sa2.sa_handler = handler2;
	ft_printf("PID = %d\n", pid);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
