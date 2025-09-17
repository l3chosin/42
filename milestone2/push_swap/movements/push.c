/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:24:16 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 13:00:52 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_node_top(t_node **dest, t_node *source)
{
	source->next = *dest;
	source->previous = (*dest)->previous;
	((*dest)->previous)->next = source;
	(*dest)->previous = source;
	*dest = source;
}

void	push(t_node **dest, t_node **source, const char *msg)
{
	t_node	*tmp;

	if (!*source)
		return ;
	tmp = *source;
	if (tmp->next == tmp)
		*source = NULL;
	else
	{
		(tmp->previous)->next = tmp->next;
		(tmp->next)->previous = tmp->previous;
		*source = tmp->next;
	}
	if (!*dest)
	{
		*dest = tmp;
		(*dest)->next = tmp;
		(*dest)->previous = tmp;
	}
	else
		insert_node_top(dest, tmp);
	ft_printf("%s\n", msg);
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b, "pa");
}

void	push_b(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a, "pb");
}
