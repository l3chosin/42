/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:06:05 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/29 12:51:24 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_mid(t_node **stack_a)
{
	int	tmp;
	int	len;

	len = list_lenght(*stack_a);
	tmp = len % 2;
	if (tmp == 0)
	{
		len /= 2;
	}
	if (tmp == 1)
	{
		len = (len / 2);
	}
	return (len);
}

void	indexer(t_node **stack)
{
	t_node	*head;
	t_node	*aux;
	int		i;
	int		current;
	int		len;

	if (!*stack)
		return ;
	head = *stack;
	i = 0;
	current = list_lowest(*stack);
	len = list_lenght(*stack);
	while (i < len)
	{
		aux = head;
		while (aux->number != current || aux->index != 0)
			aux = aux->next;
		aux->index = i + 1;
		i++;
		current = list_next_lowest(head, current);
	}
}

void	free_list(t_node *stack)
{
	t_node	*head;
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	head = stack;
	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		if (next == head)
			break ;
		current = next;
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
