/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:24:16 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/12 12:24:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
 */

 #include "../push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	tmp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = tmp;
	tmp->previous = NULL;
	*stack_a = tmp;
	ft_printf("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	tmp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = tmp;
	tmp->previous = NULL;
	*stack_b = tmp;
	ft_printf("pb\n");
}
