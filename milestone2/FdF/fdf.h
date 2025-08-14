/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:59:02 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/07 18:59:07 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_node
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_node;

int		column_row_counter(int fd, int *column, int *row);
int		read_map(int argc, char *argv[], int *column, int *row);
t_node	*array_creator(int column, int row);
void	free_split(char **array);
void	map_data_assign(int fd, t_node *map_array, int column, int row);
int		validate_columns(char *line, int expected);
int		start_window(t_node *map_array, int size, char *argv[]);
void	draw_pixels(t_node *map_array, int size, mlx_image_t *img);
t_node	*make_the_array(int argc, char *argv[], int *column, int *row);
/* Test functions */
void	test_array(t_node *map_array, int column, int row);

#endif
