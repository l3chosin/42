/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:28:30 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/17 17:28:32 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reset_fd(char *filename, int fd)
{
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: no se pudo reabrir el archivo %s\n", filename);
		return (-1);
	}
	return (fd);
}
