/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:15 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 12:10:01 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_two_case(t_node **stack, t_node *first, t_node *second)
{
	first->next = second;
	first->previous = second;
	second->next = first;
	second->previous = first;
	*stack = second;
	return ;
}

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*prev;
	t_node	*next;

	if (!*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	if (second->next == first)
	{
		swap_two_case(stack, first, second);
		return ;
	}
	prev = first->previous;
	next = second->next;
	prev->next = second;
	second->previous = prev;
	second->next = first;
	first->previous = second;
	first->next = next;
	next->previous = first;
	*stack = second;
}

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
