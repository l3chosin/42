/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:18:52 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/10 20:45:19 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(char *filename)
{
	int		file;
	int		read_status;
	char	character;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return ;
	while (1)
	{
		read_status = read(file, &character, 1);
		if (read_status <= 0)
			break ;
		write(1, &character, 1);
	}
	if (read_status < 0)
		write(2, "Cannot read file.\n", 18);
	close(file);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(argv[1]);
	return (0);
}
