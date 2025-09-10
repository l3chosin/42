/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:42:07 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/04 15:42:09 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				number;
	struct s_node*	next;
}					t_node;

t_node	*create_node(int number);

t_node	*array_to_list(int *array, int argc);

void	ft_error(int error);
int		ft_atoi_ok(const char *str,	int	*ok);
int		*arg_reader(int argc, char *argv[]);
#endif
