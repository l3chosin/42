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

	a = (*stack)->number;
	b = (*stack)->next->number;
	if (a < b)
		return ;
	else
		swap_a(stack);
}
