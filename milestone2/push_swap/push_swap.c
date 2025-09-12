/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:41:38 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/04 15:41:40 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*stack_array;
	t_node	*stack_a;
	int		i;

	i = 0;
	stack_array = arg_reader(argc, argv);
	if (stack_array == NULL)
		return (1);
	stack_a = array_to_list(stack_array, argc);
	free (stack_array);
	while (stack_a->next != NULL)
	{
		ft_printf("Nodo %d, valor %d \n", i, stack_a->number);
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}
