/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:31:44 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/05 18:31:47 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		*arr;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
	free(arr);
	arr = NULL;
}

/*#include <stdio.h>
int	main()
{
	int min = 0;
	int max = 10;
	int i = 0;
	int *result = ft_range(min, max);
	while (i < (max - min))
	{
		printf("%d ", result[i]);
		i++;
	}
	return 0;
}*/
