/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:53:01 by aluther-          #+#    #+#             */
/*   Updated: 2025/08/16 17:53:03 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**data_tokenizer(char *line)
{
	char	**tokens;

	if (!line)
		return (NULL);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	return (tokens);
}

char	**token_tokenizer(char *token)
{
	char	**values;

	if (!token)
		return (NULL);
	values = ft_split(token, ',');
	if (!values)
		return (NULL);
	return (values);
}

int	token_calculator(char **tokens)
{
	int	token_n;

	if (!tokens)
		return (0);
	token_n = 0;
	while (tokens[token_n] != NULL)
		token_n++;
	return (token_n);
}
