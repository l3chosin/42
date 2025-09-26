/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:32:22 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/19 13:23:59 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_case(t_node **stack)
{
	int	a;
	int	b;

	if (!stack || !*stack)
		return ;
	a = (*stack)->number;
	b = (*stack)->next->number;
	if (a < b)
		return ;
	else
		swap_a(stack);
}

void	three_case(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->previous->number;
	if (a > b && b > c)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a > c && c > b)
		rotate_a(stack);
	else if (b > a && a > c)
		reverse_rotate_a(stack);
	else if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void	four_case(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;

	min = lowest_node(*stack_a);
	while ((*stack_a)->number != min->number)
		rotate_a(stack_a);
	push_b(stack_b, stack_a);
	three_case(stack_a);
	push_a(stack_a, stack_b);
}

void	five_case(t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_node	*min;

	i = 0;
	while (i < 2)
	{
		position_assign(stack_a);
		min = lowest_node(*stack_a);
		while ((*stack_a)->number != min->number)
		{
			if (min->position <= list_lenght(*stack_a) / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
			position_assign(stack_a);
		}
		push_b(stack_b, stack_a);
		i++;
	}
	three_case(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	final_check(stack_a);
}

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	if (!stack || stack->next == stack)
		return (1);
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->index > stack->index)
		return (0);
	return (1);
}
