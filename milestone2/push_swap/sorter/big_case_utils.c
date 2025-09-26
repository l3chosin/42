/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_case_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:31:57 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/26 15:02:08 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_push(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	pushed;
	int	rotations;
	int	mid_low;
	int	mid_high;

	len = list_lenght(*stack_a);
	pushed = 0;
	rotations = 0;
	mid_low = len / 3;
	mid_high = (2 * len) / 3;
	while (pushed < 2 && rotations < len && len > 3)
	{
		if ((*stack_a)->index > mid_low && (*stack_a)->index < mid_high)
		{
			push_b(stack_b, stack_a);
			pushed++;
			len--;
		}
		else
		{
			rotate_a(stack_a);
			rotations++;
		}
	}
	while (pushed < 2 && len-- > 0)
	{
		push_b(stack_b, stack_a);
		pushed++;
	}
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
