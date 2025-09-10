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
	int	*stack_a;
	int	i;

	i = 0;
	stack_a = arg_reader(argc, argv);
	if (stack_a == NULL)
		return (1);
	while (i < argc - 1)
	{
		ft_printf("\n%d", stack_a[i]);
		i++;
	}
	return (0);
}
