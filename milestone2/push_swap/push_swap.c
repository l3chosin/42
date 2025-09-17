/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:41:38 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 13:28:18 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*stack_array;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	stack_array = arg_reader(argc, argv);
	if (stack_array == NULL)
		return (1);
	stack_a = array_to_list(stack_array, argc - 1);
	free (stack_array);
	stack_b = NULL;
	return (0);
}
