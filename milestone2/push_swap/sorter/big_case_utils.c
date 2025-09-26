/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_case_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:31:57 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/26 15:02:08 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_possition_cost(t_node **stack, int mid)
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

void	objective_position(t_node	**stack_a, t_node **stack_b)
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
		current_a->objective_above = tmp_b->avobe;
		current_a = current_a->next;
		if (current_a == head_a)
			break ;
	}
}

int	calc_combined_cost(t_node *current, t_node *objective)
{
	if ((current->avobe == 1 && objective->avobe == 1)
		|| (current->avobe == 0 && objective->avobe == 0))
	{
		if (current->position_cost > objective->position_cost)
			return (current->position_cost);
		return (objective->position_cost);
	}
	return (current->position_cost + objective->position_cost);
}

void	total_cost_calculator(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	t_node	*current;
	t_node	*objective;

	if (!stack_a || !*stack_a)
		return ;
	head = *stack_a;
	current = *stack_a;
	while (current)
	{
		objective = objective_node(current->objective, *stack_b);
		current->total_cost = calc_combined_cost(current, objective) + 1;
		current = current->next;
		if (current == head)
			break ;
	}
}
