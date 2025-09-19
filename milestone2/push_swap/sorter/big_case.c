/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:16:46 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/19 12:59:12 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	first_push(t_node **stack_a, t_node **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
}

static void	find_cheapest_b(t_node **stack_a, t_node **stack_b)
{
	int	middle;
	int	i;

	middle = calc_mid(stack_a);
	i = 0;
}

void	big_case(t_node **stack_a, t_node **stack_b)
{
	first_push(stack_a, stack_b);
	find_cheapest_b(stack_a, stack_b);
}
