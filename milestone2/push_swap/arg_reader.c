/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:26:48 by aluther-          #+#    #+#             */
/*   Updated: 2025/09/29 12:54:54 by aluther-         ###   ########.fr       */
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
			return (NULL);
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
	int	*tmp;

	i = 1;
	j = 0;
	if (argc < 2)
		return (NULL);
	stack = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		stack[j] = arg_checker(argv[i], &ok);
		if (ok == 0)
			return (free(stack), ft_error(1), NULL);
		tmp = already_number(stack[j], stack, j);
		if (tmp == NULL)
			return (free(stack), ft_error(1), NULL);
		stack = tmp;
		i++;
		j++;
	}
	return (stack);
}
