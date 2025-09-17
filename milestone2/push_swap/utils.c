/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:16:41 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 11:30:40 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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