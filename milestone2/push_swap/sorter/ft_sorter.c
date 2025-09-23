/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:55:14 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 14:55:51 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sorter(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = list_lenght(*stack_a);
	if (len == 2)
		two_case(stack_a);
	if (len == 3)
		three_case(stack_a);
	if (len >= 4)

}
