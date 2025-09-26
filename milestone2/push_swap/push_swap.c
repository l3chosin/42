/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:41:38 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/26 14:57:05 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*stack_array;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_array = arg_reader(argc, argv);
	if (stack_array == NULL)
		return (1);
	stack_a = array_to_list(stack_array, argc - 1);
	free (stack_array);
	stack_b = NULL;
	indexer(&stack_a);
	ft_sorter(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
