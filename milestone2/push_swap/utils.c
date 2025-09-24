/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:16:41 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 14:55:44 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_lenght(t_node *stack)
{
	t_node	*head;
	int		len;

	if (!stack)
		return (0);
	head = stack;
	len = 1;
	stack = stack->next;
	while (stack != head)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_node	*create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->number = number;
	new_node->position_cost = 0;
	new_node->index = 0;
	new_node->position = 0;
	new_node->objective = 0;
	new_node->avobe = 0;
	new_node->total_cost = 0;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

int	list_lowest(t_node *stack)
{
	t_node	*head;
	int		lowest;

	head = stack;
	lowest = stack->number;
	stack = stack->next;
	while (stack != head)
	{
		if (stack->number < lowest)
			lowest = stack->number;
		stack = stack->next;
	}
	return (lowest);
}

t_node	*list_lowest_cost(t_node *stack)
{
	t_node	*head;
	t_node	*lowest_h;
	int		lowest;

	if (!stack)
		return (NULL);
	head = stack;
	lowest_h = stack;
	lowest = stack->total_cost;
	stack = stack->next;
	while (stack != head)
	{
		if (stack->total_cost < lowest)
		{
			lowest = stack->total_cost;
			lowest_h = stack;
		}
		stack = stack->next;
	}
	return (lowest_h);
}

int	list_next_lowest(t_node *stack, int ref)
{
	t_node	*head;
	int		next_lowest;
	int		first;

	head = stack;
	first = 1;
	next_lowest = INT_MAX;
	while (stack && (stack != head || first))
	{
		if (stack->number > ref && stack->number < next_lowest)
			next_lowest = stack->number;
		stack = stack->next;
		first = 0;
	}
	return (next_lowest);
}
