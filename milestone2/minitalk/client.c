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

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		ft_printf("Error! Use the client as following\n");
		ft_printf("./client PID \"YourMessageHere\"\n");
		return (0);
	}
}
