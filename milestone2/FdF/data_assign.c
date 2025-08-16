/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:22:06 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/15 21:22:08 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int hex_to_uint(const char *hex)
{
    unsigned int result = 0;
    int i = 0;
    char c;

    if (!hex)
        return (0xFFFFFF);
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        i = 2;
    c = hex[i];
    while ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
    {
        result *= 16;
        if (c >= '0' && c <= '9')
            result += c - '0';
        else if (c >= 'a' && c <= 'f')
            result += c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            result += c - 'A' + 10;
        i++;
        c = hex[i];
    }
    return (result);
}

void fill_row_nodes(t_node *map_array, char **tokens, int col, int y)
{
    int x = 0;
    char **values;

    while (x < col && tokens[x])
    {
        values = token_tokenizer(tokens[x]);
        map_array[y * col + x].x = x;
        map_array[y * col + x].y = y;
        map_array[y * col + x].z = ft_atoi(values[0]);
        map_array[y * col + x].color = hex_to_uint(values[1]);
        free_split(values);
        x++;
    }
}

void	data_assign(t_node *map_array, int col, int row, char *argv[])
{
	int		fd;
	int		y;
	char	*line;
	char	**tokens;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return;
	line = get_next_line(fd);
	while (line != NULL && y < row)
	{
		tokens = data_tokenizer(line);
		fill_row_nodes(map_array, tokens, col, y);
		free_split(tokens);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
}
