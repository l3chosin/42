/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:15 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 13:27:30 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **stack)
{
	int	tmp;

	if ((*stack)->next == *stack || !*stack)
		return ;
	else
	{
		tmp = (*stack)->number;
		(*stack)->number = ((*stack)->next)->number;
		((*stack)->next)->number = tmp;
	}
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
