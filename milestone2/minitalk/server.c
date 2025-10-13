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
/* Falta hacer la funcion Handler. Creo que el problema esta justo en esta funcion
 * puede que sea sincronizacion o algo, lo desconozco aun
 */
int	main(void)
{
	struct sigaction	sa;
	int					pid;


	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
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
