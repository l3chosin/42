/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:16:46 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/19 12:59:12 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	add_possition_cost(t_node **stack, int mid)
{
	int		len;
	t_node	*curr;
	t_node	*head;

	if (!stack || !(*stack))
		return ;
	len = list_lenght(*stack);
	head = *stack;
	curr = *stack;
	while (1)
	{
		if (curr->position < mid)
		{
			curr->position_cost = curr->position;
			curr->avobe = 1;
		}
		else
		{
			curr->position_cost = len - curr->position;
			curr->avobe = 0;
		}
		curr = curr->next;
		if (curr == head)
			break ;
	}
}

static void	objective_position(t_node	**stack_a, t_node **stack_b)
{
	t_node	*head_a;
	t_node	*current_a;
	t_node	*tmp_b;
	int		ref;

	head_a = *stack_a;
	current_a = head_a;
	while (current_a)
	{
		ref = current_a->index;
		tmp_b = *stack_b;
		while (!((ref < tmp_b->previous->index && ref > tmp_b->index)
				|| (tmp_b->previous->index < tmp_b->index
					&& (ref > tmp_b->index || ref < tmp_b->previous->index))))
		{
			tmp_b = tmp_b->next;
		}
		current_a->objective = tmp_b->position;
		current_a = current_a->next;
		if (current_a == head_a)
			break ;
	}
}

static	void	total_cost_calculator(t_node **stack)
{
	t_node	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	while (*stack)
	{
		(*stack)->total_cost = (*stack)->position_cost
			+ 1 + (*stack)->objective;
		*stack = (*stack)->next;
		if (*stack == head)
			break ;
	}
}

static	void	cost_calc(t_node **stack_a, t_node **stack_b)
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
	total_cost_calculator(stack_a);
}

void	big_case(t_node **stack_a, t_node **stack_b)
{
	first_push(stack_a, stack_b);
	cost_calc(stack_a, stack_b);
}
