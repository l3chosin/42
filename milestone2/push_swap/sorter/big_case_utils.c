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

int	calc_mid(t_node **stack_a)
{
	int	tmp;
	int	len;
	int	mid;

	len = list_lenght(*stack_a);
	tmp = len % 2;
	if (tmp == 0)
	{
		len /= 2;
	}
	if (tmp == 1)
	{
		len = (len / 2) + 1;
	}
	return (len);
}

void	indexer(t_node **stack)
{
	t_node *head;
	int		i;
	int		current;
	int		list_len;

	list_len = list_lenght(stack);
	head = (*stack);
	i = 0;
	current = list_lowest(stack);
	while ((*stack)->number != current)
		stack = (*stack)->next;
	(*stack)->index = i;
	i++;
	while (i < list_len)
	{
		*stack = head;
		current = list_next_lowest(stack, current);
		while ((*stack)->number != current)
			stack = (*stack)->next;
		(*stack)->index = i;
		i++;
	}	
}
