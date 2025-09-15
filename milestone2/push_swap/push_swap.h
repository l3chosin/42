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
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

//*				MOVEMENTS			 *//

//	push.c
void	insert_node_top(t_node **dest, t_node *source);
void	push(t_node **dest, t_node **source, const char *msg);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_b, t_node **stack_a);

//reverse_rotate.c
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);

//rotate.c
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rr(t_node **stack_a, t_node **stack_b);

//swap.c
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_both(t_node **stack_a, t_node **stack_b);


//*					UTILS.C				 *//
t_node	*create_node(int number);


//*					ARRAY_TO_LIST.C		 *//
t_node	*array_to_list(int *array, int argc);


/*					ERROR_UTILS.C			 */
void	ft_error(int error);


/*					FT_ATOI_CHECKER.C		 */
int		ft_atoi_ok(const char *str,	int	*ok);


/*					ARG_READER.C			 */
int		*arg_reader(int argc, char *argv[]);
#endif
