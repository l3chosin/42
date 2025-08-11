/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:47:22 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/11 16:47:24 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    column_row_counter(int fd, int *column, int *row)
{
    int i;
    char *line;

    *column = 0;
    *row = 0;

    line = get_next_line(fd);
    if(!line)
        return;
    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
    {
        if(line[i] == ' ')
            (*column)++;
        i++;
    }
    (*column)++;
    (*row)++;
    free(line);
    while((line = get_next_line(fd)) != NULL)
    {
        (*row)++;
        free(line);
    }
    return;
}
