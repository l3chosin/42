/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:06:05 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/22 14:55:42 by aluther-         ###   ########.fr       */
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

void	print_list(t_node *stack)
{
	t_node	*head;

	if (!stack)
	{
		ft_printf("Sorry, there is no stack avaliable :(\n");
		return ;
	}
	head = stack;
	while (stack->next != head)
	{
		ft_printf("%d ", stack->number);
		stack = stack->next;
	}
	ft_printf("%d\n", stack->number);
	stack = stack->next;
}

/* TESTING FUNCTIONS, descomentar para utilizarlas */
/*void	print_all_nodes_info(t_node *stack)
{
	t_node	*head;

	if (!stack)
	{
		ft_printf("Lista vacía\n");
		return ;
	}
	head = stack;
	ft_printf("=== NODE INFO ===\n");
	ft_printf("number: %d, position_cost: %d, index: %d, position: %d, objective: %d, above: %d, total_cost: %d\n",
		stack->number, stack->position_cost, stack->index,
		stack->position, stack->objective, stack->avobe, stack->total_cost);
	stack = stack->next;
	while (stack != head)
	{
		ft_printf("number: %d, position_cost: %d, index: %d, position: %d, objective: %d, above: %d, total_cost: %d\n",
			stack->number, stack->position_cost, stack->index,
			stack->position, stack->objective, stack->avobe, stack->total_cost);
		stack = stack->next;
	}
	ft_printf("=== END ===\n");
	}*/
