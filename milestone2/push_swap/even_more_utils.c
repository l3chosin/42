/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:18:38 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/26 15:19:07 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_assign(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;
	int		p;

	if (!stack || !*stack)
		return ;
	head = *stack;
	tmp = *stack;
	p = 0;
	while (tmp)
	{
		tmp->position = p;
		tmp = tmp->next;
		p++;
		if (tmp == head)
			break ;
	}
}

t_node	*objective_node(int obj, t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp && tmp->position != obj)
		tmp = tmp->next;
	return (tmp);
}

void	semifinal(t_node **stack_b)
{
	int		mid_b;
	t_node	*first_node;

	mid_b = calc_mid(stack_b);
	position_assign(stack_b);
	add_possition_cost(stack_b, mid_b);
	first_node = find_first(*stack_b);
	if (first_node->avobe == 1)
	{
		while (*stack_b != first_node)
			rotate_b(stack_b);
	}
	else
	{
		while (*stack_b != first_node)
			reverse_rotate_b(stack_b);
	}
}

void	final_check(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	position_assign(stack);
	add_possition_cost(stack, list_lenght(*stack) / 2);
	while (tmp->index != 1)
		tmp = tmp->next;
	while (*stack != tmp)
	{
		if (tmp->avobe == 1)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}

void	cost_calc(t_node **stack_a, t_node **stack_b)
{
	int	mid_a;
	int	mid_b;

	mid_a = calc_mid(stack_a);
	mid_b = calc_mid(stack_b);
	position_assign(stack_a);
	position_assign(stack_b);
	add_possition_cost(stack_a, mid_a);
	add_possition_cost(stack_b, mid_b);
	objective_position(stack_a, stack_b);
	total_cost_calculator(stack_a, stack_b);
}
