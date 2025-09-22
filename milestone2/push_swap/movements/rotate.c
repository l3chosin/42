/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:09 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 12:18:08 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_both(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_b);
	rotate(stack_a);
	ft_printf("rr\n");
}
