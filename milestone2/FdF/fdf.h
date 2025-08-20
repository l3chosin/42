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

unsigned int	hex_to_uint(const char *hex);
void			fill_row_nodes(t_node *map_array,
					char **tokens, int col, int y);
void			data_assign(t_node *map_array, int col, int row, char *argv[]);

void			free_split(char **array);
int				col_counter(char *line);
int				row_counter(int fd, int col_expected);
int				open_map(int argc, char *argv[]);
int				read_map_create_array(int argc, char *argv[],
					t_node **map_array);

char			**data_tokenizer(char *line);
char			**token_tokenizer(char *token);
int				token_calculator(char **tokens);

int				reset_fd(char *filename, int fd);

int				validate_line(char *line, int expected_col, int row);
int				validate_map(int fd, int *out_col, int *out_row);

void 			open_window(int width, int heigth, char *argv[]);

/* Funciones de prueba, borrar antes de entregar */
void			print_map_array(t_node *map_array, int col, int row);

#endif
