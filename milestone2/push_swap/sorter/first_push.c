/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:20:14 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/26 17:20:15 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push_middle(t_node **a, t_node **b, int len)
{
	int	pushed;
	int	rot;

	pushed = 0;
	rot = 0;
	while (pushed < 2 && rot < len && len > 3)
	{
		if ((*a)->index > len / 3 && (*a)->index < (2 * len) / 3)
		{
			push_b(b, a);
			pushed++;
			len--;
		}
		else
		{
			rotate_a(a);
			rot++;
		}
	}
	return (pushed);
}

void	first_push(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	pushed;

	len = list_lenght(*stack_a);
	pushed = push_middle(stack_a, stack_b, len);
	while (pushed < 2 && len-- > 0)
	{
		push_b(stack_b, stack_a);
		pushed++;
	}
}
