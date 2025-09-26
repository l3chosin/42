/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:16:46 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/26 15:01:01 by aluther-         ###   ########.fr       */
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
		current_a->objective_above = tmp_b->avobe;
		current_a = current_a->next;
		if (current_a == head_a)
			break ;
	}
}

static void total_cost_calculator(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	t_node	*current;
	t_node	*objective;
	int		combined_cost;

	if (!stack_a || !*stack_a)
		return ;
	head = *stack_a;
	current = *stack_a;
	while (current)
	{
		objective = objective_node(current->objective, *stack_b);
		if ((current->avobe == 1 && objective->avobe == 1) ||
			(current->avobe == 0 && objective->avobe == 0))
		{
			if (current->position_cost > objective->position_cost)
				combined_cost = current->position_cost;
			else
				combined_cost = objective->position_cost;
		}
		else
		{
			combined_cost = current->position_cost + objective->position_cost;
		}
		current->total_cost = combined_cost + 1;
		current = current->next;
		if (current == head)
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
	total_cost_calculator(stack_a, stack_b);
}

static	void	semifinal(t_node **stack_b)
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

void	big_case(t_node **stack_a, t_node **stack_b)
{
	t_node	*lowest;
	t_node	*objective;
	int		len_a;
	int		len_b;

	first_push(stack_a, stack_b);
	len_a = list_lenght(*stack_a);
	while (len_a > 0)
	{
		cost_calc(stack_a, stack_b);
		lowest = list_lowest_cost(*stack_a);
		objective = objective_node(lowest->objective, *stack_b);
		if (lowest->avobe == 1 && objective->avobe == 1)
		{
			while (lowest != (*stack_a) && objective != *stack_b)
				rotate_both(stack_a, stack_b);
		}
		else if (lowest->avobe == 0 && objective->avobe == 0)
		{
			while (lowest != (*stack_a) && objective != *stack_b)
				reverse_rotate_both(stack_a, stack_b);
		}
		while ((*stack_a) != lowest)
		{
			if (lowest->avobe == 1)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		while (*stack_b != objective)
		{
			if (objective->avobe == 1)
				rotate_b(stack_b);
			else
				reverse_rotate_b(stack_b);
		}
		push_b(stack_b, stack_a);
		len_a = list_lenght(*stack_a);
	}
	semifinal(stack_b);
	len_b = list_lenght(*stack_b);
	while (len_b != 0)
	{
		push_a(stack_a, stack_b);
		len_b = list_lenght(*stack_b);
	}
}
