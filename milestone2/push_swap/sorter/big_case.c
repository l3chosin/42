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
#include <unistd.h>

static void	first_push(t_node **stack_a, t_node **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	two_case(stack_b);
}

static void	position_assign(t_node **stack)
{
	t_node	*head;
	int		p;

	head = *stack;
	p = 0;
	if (!head)
		return ;
	while ((*stack)->next != head)
	{
		(*stack)->position = p;
		*stack = (*stack)->next;
		p++;
	}
}

static void	add_possition_cost(t_node **stack, int mid)
{
	int		len;
	t_node	*head;

	if (!stack || !(*stack))
		return ;
	len = list_lenght(*stack);
	head = *stack;
	while (*stack)
	{
		if ((*stack)->position <= mid)
		{
			(*stack)->cost = (*stack)->position;
			(*stack)->avobe = 1;
		}
		else
		{
			(*stack)->cost = len - (*stack)->position;
			(*stack)->avobe = 0;
		}
		(*stack) = (*stack)->next;
		if ((*stack) == head)
			break ;
	}
	*stack = head;
}

static void	objective_position(t_node	**stack_a, t_node **stack_b)
{
	int		ref;
	t_node	*head_a;
	t_node	*head_b;
	t_node	*current_a;

	head_a = *stack_a;
	current_a = head_a;
	while (current_a)
	{
		head_b = *stack_b;
		ref = current_a->index;
		while (!(ref < (*stack_b)->index
				&& ref > (*stack_b)->previous->index))
		{
			*stack_b = (*stack_b)->next;
			if (*stack_b == head_b)
				break ;
		}
		current_a->objective = (*stack_b)->position;
		*stack_b = head_b;
		current_a = current_a->next;
		if (current_a == head_a)
			break ;
	}
}

static	void	total_cost_calculator(t_node **stack_a, t_node **stack_b,
	int mid_a, int mid_b)
{

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
	total_cost_calculator(stack_a, stack_b, mid_a, mid_b);
}

void	big_case(t_node **stack_a, t_node **stack_b)
{
	first_push(stack_a, stack_b);
	cost_calc(stack_a, stack_b);

}
