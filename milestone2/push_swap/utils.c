/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:16:41 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/19 12:59:33 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_lenght(t_node *stack)
{
	t_node	*head;
	int		len;

	len = 0;
	if (!stack)
		return (len);
	head = stack;
	while (stack->next != head)
	{
		stack = stack->next;
		len++;
	}
	len++;
	stack = stack->next;
	return (len);
}

t_node	*create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->number = number;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}
void	print_list(t_node *stack)
{
	t_node *head;
	
	if (!stack)
	{
		ft_printf("Sorry, there is no stack avaliable :(\n");
		return ;
	}
	head = stack;
	while (stack->next != head)
	{
		ft_printf("%d ", stack->number);
		stack = stack->next;
	}
	ft_printf("%d\n", stack->number);
	stack = stack->next;
}
int	list_lowest(t_node *stack)
{
	t_node *head;
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
int	list_next_lowest(t_node *stack, int ref)
{
	t_node *head;
	int		next_lowest;

	head = stack;
	next_lowest = INT_MAX;
	stack = stack->next;
	while (stack != head)
	{
		if (stack->number > ref && stack->number < next_lowest) 
			next_lowest = stack->number;
		stack = stack->next;
	}
	return (next_lowest);
}