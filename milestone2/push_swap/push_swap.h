/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:42:07 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 14:55:46 by aluther-         ###   ########.fr       */
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
	int				position_cost;
	int				index;
	int				position;
	int				objective;
	int				avobe;
	int				total_cost;
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
void	rotate_both(t_node **stack_a, t_node **stack_b);

//swap.c
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_both(t_node **stack_a, t_node **stack_b);

/*					SORTER				*/

/* 	big_case. c*/
void	big_case(t_node **stack_a, t_node **stack_b);

/* 	big_case_utils.c*/
int		calc_mid(t_node **stack_a);
void	first_push(t_node **stack_a, t_node **stack_b);
void	position_assign(t_node **stack);
void	indexer(t_node **stack);
/*  ft_sorter.c */
void	ft_sorter(t_node **stack_a, t_node **stack_b);
/*	sort_utils.c  */
void	two_case(t_node **stack);
/*	three_case.c */
void	three_case(t_node **stack);
//*					UTILS.C				 *//
t_node	*create_node(int number);
void	print_list(t_node *stack);
int		list_lenght(t_node *stack);
int		list_lowest(t_node *stack);
int		list_next_lowest(t_node *stack, int ref);
void	print_all_nodes_info(t_node *stack);
/*  utils_2.c */
int		calc_mid(t_node **stack_a);
void	indexer(t_node **stack);
//*					ARRAY_TO_LIST.C		 *//
t_node	*array_to_list(int *array, int argc);

/*					ERROR_UTILS.C			 */
void	ft_error(int error);

/*					FT_ATOI_CHECKER.C		 */
int		ft_atoi_ok(const char *str,	int	*ok);

/*					ARG_READER.C			 */
int		*arg_reader(int argc, char *argv[]);
#endif
