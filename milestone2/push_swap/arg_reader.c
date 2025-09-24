/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:26:48 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/17 13:26:51 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*already_number(int n, int *stack, int j_index)
{
	int	i;

	i = 0;
	while (i < j_index)
	{
		if (n == stack[i])
			return (ft_error(3), NULL);
		i++;
	}
	return (stack);
}

static int	arg_checker(char *number, int *ok)
{
	int	n;

	n = ft_atoi_ok(number, ok);
	return (n);
}

int	*arg_reader(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*stack;
	int	ok;

	i = 1;
	j = 0;
	if (argc < 2)
		return (ft_error(1), NULL);
	stack = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		stack[j] = arg_checker(argv[i], &ok);
		if (ok == 0)
			return (ft_error(2), ft_printf(" %d\n", i),
				ft_error(4), free(stack), NULL);
		stack = already_number(stack[j], stack, j);
		if (stack == NULL)
			return (ft_error(4), free(stack), NULL);
		i++;
		j++;
	}
	return (stack);
}
