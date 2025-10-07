/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:55:14 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 14:55:51 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*lowest_node(t_node *stack)
{
	t_node	*min;
	t_node	*tmp;

	if (!stack)
		return (NULL);
	min = stack;
	tmp = stack->next;
	while (tmp && tmp != stack)
	{
		if (tmp->number < min->number)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static	int	first_check(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	if (tmp->number > tmp->next->number)
		return (0);
	tmp = tmp->next;
	while (tmp->next != stack)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sorter(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	sorted;

	len = list_lenght(*stack_a);
	sorted = first_check(*stack_a);
	if (sorted == 0)
	{
		if (len == 2)
			two_case(stack_a);
		else if (len == 3)
			three_case(stack_a);
		else if (len == 4)
			four_case(stack_a, stack_b);
		else if (len == 5)
			five_case(stack_a, stack_b);
		else if (len > 5)
			big_case(stack_a, stack_b);
	}
}
