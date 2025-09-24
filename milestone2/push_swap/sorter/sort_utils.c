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
