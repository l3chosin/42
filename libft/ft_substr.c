/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:47:21 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/26 15:31:50 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	ptr = malloc((len - start) * (sizeof (char)));
	if (ptr == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < len)
	{
		ptr[j] = s[i];
		i++;
		j++;
	}
	return (ptr);
}

/*#include <stdio.h>
int	main()
{
	char const s[] = "Hola mundo";
	char *p;

	p = ft_substr(s, 3, 11);
	printf("Resultado de la substring: %s", p);
	return 0;
}*/
