/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:42:07 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/29 12:52:59 by aluther-         ###   ########.fr       */
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
	int				objective_above;
	int				avobe;
	int				total_cost;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

void	insert_node_top(t_node **dest, t_node *source);
void	push(t_node **dest, t_node **source, const char *msg);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_b, t_node **stack_a);

void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);

void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_both(t_node **stack_a, t_node **stack_b);

void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_both(t_node **stack_a, t_node **stack_b);
void	big_case(t_node **stack_a, t_node **stack_b);

int		calc_mid(t_node **stack_a);
void	first_push(t_node **stack_a, t_node **stack_b);
void	position_assign(t_node **stack);
t_node	*objective_node(int obj, t_node *stack);
void	indexer(t_node **stack);
t_node	*find_first(t_node *stack);

void	add_possition_cost(t_node **stack, int mid);
void	objective_position(t_node	**stack_a, t_node **stack_b);
void	total_cost_calculator(t_node **stack_a, t_node **stack_b);
void	cost_calc(t_node **stack_a, t_node **stack_b);
void	semifinal(t_node **stack_b);

void	ft_sorter(t_node **stack_a, t_node **stack_b);
t_node	*lowest_node(t_node *stack);

int		is_sorted(t_node *stack);
void	two_case(t_node **stack);
void	final_check(t_node **stack);
void	four_case(t_node **stack_a, t_node **stack_b);
void	five_case(t_node **stack_a, t_node **stack_b);

void	three_case(t_node **stack);

t_node	*create_node(int number);
void	print_list(t_node *stack);
int		list_lenght(t_node *stack);
int		list_lowest(t_node *stack);
int		list_next_lowest(t_node *stack, int ref);
t_node	*list_lowest_cost(t_node *stack);
void	print_all_nodes_info(t_node *stack);
void	free_list(t_node *stack);

int		calc_mid(t_node **stack_a);
void	indexer(t_node **stack);

t_node	*array_to_list(int *array, int argc);

void	ft_error(int error);

int		ft_atoi_ok(const char *str,	int	*ok);

int		*arg_reader(int argc, char *argv[]);
#endif
