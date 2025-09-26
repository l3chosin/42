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

void	do_double_rotate(t_node **a, t_node **b, t_node *lowest,
	t_node *objective)
{
	if (lowest->avobe == 1 && objective->avobe == 1)
		while (lowest != *a && objective != *b)
			rotate_both(a, b);
	else if (lowest->avobe == 0 && objective->avobe == 0)
		while (lowest != *a && objective != *b)
			reverse_rotate_both(a, b);
}

void	do_single_rotate_a(t_node **a, t_node *lowest)
{
	while (*a != lowest)
	{
		if (lowest->avobe == 1)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	do_single_rotate_b(t_node **b, t_node *objective)
{
	while (*b != objective)
	{
		if (objective->avobe == 1)
			rotate_b(b);
		else
			reverse_rotate_b(b);
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
	while (len_a-- > 0)
	{
		cost_calc(stack_a, stack_b);
		lowest = list_lowest_cost(*stack_a);
		objective = objective_node(lowest->objective, *stack_b);
		do_double_rotate(stack_a, stack_b, lowest, objective);
		do_single_rotate_a(stack_a, lowest);
		do_single_rotate_b(stack_b, objective);
		push_b(stack_b, stack_a);
	}
	semifinal(stack_b);
	len_b = list_lenght(*stack_b);
	while (len_b-- > 0)
		push_a(stack_a, stack_b);
	final_check(stack_a);
}
