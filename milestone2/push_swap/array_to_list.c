/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:40 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 13:27:43 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*array_to_list(int *array, int argc)
{
	int		i;
	t_node	*head;
	t_node	*current;

	if (argc <= 0)
		return (NULL);
	head = create_node(array[0]);
	if (!head)
		return (NULL);
	current = head;
	i = 1;
	while (i < argc)
	{
		current->next = create_node(array[i]);
		if (!current->next)
			return (free_list(head), NULL);
		current->next->previous = current;
		current = current->next;
		i++;
	}
	current->next = head;
	head->previous = current;
	return (head);
}
