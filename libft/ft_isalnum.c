/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:49:10 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/13 16:05:06 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))
		|| ((c >= '0') && (c <= '9')))
		return (1);
	return (0);
}

/*#include <stdio.h>
int main ()
{
    int r;
    int c;

    c = '*';
    r = ft_isalnum(c);

    printf("Result is: %d", r);
    return (0);
}*/
