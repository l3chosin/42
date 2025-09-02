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
# include <math.h>

typedef struct s_node
{
	int				x;
	int				y;
	int				z;
	double			px;
	double			py;
	unsigned int	color;
}	t_node;

typedef struct s_extra
{
	int		offsetx;
	int		offsety;
	int		scale;
	int		col;
	int		row;
	int		total;
	t_node	*map_array;
}	t_extra;

typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

unsigned int	hex_to_uint(const char *hex);
void			fill_row_nodes(t_node *map_array,
					char **tokens, int col, int y);
void			data_assign(t_node *map_array, int col, int row, char *argv[]);

void			free_split(char **array);
int				col_counter(char *line);
int				row_counter(int fd, int col_expected);
int				open_map(int argc, char *argv[]);
int				read_map_create_array(int argc, char *argv[],
					t_node **map_array, int *col);

char			**data_tokenizer(char *line);
char			**token_tokenizer(char *token);
int				token_calculator(char **tokens);

int				reset_fd(char *filename, int fd);
int				scale_calculator(t_node *map_array, int total);
void			calculate_offset(t_node *map_array, t_extra *map_extras);
void			iso_converter(t_node *map_array, int total);
uint32_t		ft_strtoul(const char *str);

int				validate_line(char *line, int expected_col, int row);
int				validate_map(int fd, int *out_col, int *out_row);

mlx_image_t		*draw_map(mlx_image_t *img, t_extra *map_extras,
					t_node *map_array);
void			open_window(t_extra *map_extras, t_node *map_array);

void			put_pixel_safe(mlx_image_t *img, int x, int y, uint32_t color);

void			draw_line(mlx_image_t *img, t_node *map_array,
					t_extra *map_extras, int index);

/* Funciones de prueba, borrar antes de entregar */
void			print_map_array(t_node *map_array, int col, int row);

#endif
