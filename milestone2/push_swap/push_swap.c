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
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int	*stack_array;
	t_node *stack;
	int	i;

	i = 0;
	stack_array = arg_reader(argc, argv);
	if (stack_array == NULL)
		return (1);
	stack = array_to_list(stack_array, argc);
	turkey_sorter(stack);
	return (0);
}
