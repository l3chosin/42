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

int		col_counter(char *line);
int		row_counter(int fd, int col_expected);
int		open_map(int argc, char *argv[]);
int		read_map_create_array(int argc, char *argv[], t_node **map_array);
void	free_split(char **array);
void	data_assign(t_node *map_array, int col, int row, char *argv[]);
char	**data_tokenizer(char *line);
char	**token_tokenizer(char *token);
int		token_calculator(char **tokens);
void 	print_map_array(t_node *map_array, int col, int row);

#endif
