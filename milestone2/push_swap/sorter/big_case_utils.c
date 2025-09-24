/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_case_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:31:57 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/19 13:23:43 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_push(t_node **stack_a, t_node **stack_b)
{
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
}

void	position_assign(t_node **stack)
{
	t_node	*head;
	int		p;

	head = *stack;
	p = 0;
	if (!head)
		return ;
	while (*stack)
	{
		(*stack)->position = p;
		*stack = (*stack)->next;
		p++;
		if (*stack == head)
			break ;
	}
}

t_node	*find_first(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->index != 1)
		tmp = tmp->next;
	return (tmp);
}

t_node	*objective_node(int obj, t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->position != obj)
		tmp = tmp->next;
	return (tmp);
}
