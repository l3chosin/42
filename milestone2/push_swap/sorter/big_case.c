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
	two_case(stack_b);
}

static void	position_assign(t_node **stack)
{
	t_node *head;
	int	p;

	head = *stack;
	p = 0;
	if (!head)
		return ;
	while ((*stack)->next != head)
	{
		(*stack)->position = p;
		*stack = (*stack)->next;
		p++;
	}
}

static void	add_possition_cost(t_node **stack, int mid)
{
	int		len;
	int		i;
	int		j;
	t_node	*tmp;

	if (!stack)
		return ;
	len = list_lenght(*stack);
	i = 0;
	j = 0;
	tmp = *stack;
	while (tmp->position <= mid)
	{
		tmp->cost += i;
		tmp = tmp->next;
		i++;
	}
	while (tmp->position > mid && tmp->position <= len)
	{
		tmp->cost = i - j;
		tmp = tmp->next;
		j++;
	}
}

static	void	cost_calc(t_node **stack_a, t_node **stack_b)
{
	int	mid_a;
	int	mid_b;

	mid_a = calc_mid(stack_a);
	mid_b = calc_mid(stack_b);
	add_possition_cost(stack_a, mid_a);
	add_possition_cost(stack_b, mid_b);
}

void	big_case(t_node **stack_a, t_node **stack_b)
{
	int	mid_a;
	int	mid_b;

	mid_a = calc_mid(stack_a);
	mid_b = calc_mid(stack_b);
	first_push(stack_a, stack_b);
	position_assign(stack_a);
	position_assign(stack_b);
}
